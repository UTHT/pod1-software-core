#include "channel.hpp"

Channel::Channel(string channel_name, double min_value, double max_value) {
    this->channel_name = channel_name;
    this->min_value = min_value;
    this->max_value = max_value;

    // Defaulted this to the current time
    time(&this->last_comm_time);
}

// Should return an ENUM
int Channel::validateCurrentValue() {
    time_t current_comm_time; 

    // Update the current time 
    time(&current_comm_time); 

    // Get the difference between current time and the last communicated time
    double time_diff = difftime(current_comm_time, this->last_comm_time); 

    // Check time
    if (time_diff >= 60.0) {
        return ChannelStatus::NO_COMMS;
    }

    // Check value within range
    if (this->current_value < this->min_value || this->current_value > this->max_value) {
        return ChannelStatus::OUT_OF_RANGE;
    }

    // TODO: (Maybe) Check the frequency of data 
    // 1) What are the acceptable bounds?

    // Default return value
    return ChannelStatus::FUNCTIONING;
}

// This is a static function (instead of a method function)
void Channel::callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_msg* msg, void* user) {
    // Get the pointer to the channel
    string channelString(channel);
    Channel* channelObj = channel_map[channelString];
    cout << "Received message on channel: " << channelString << endl;

    // TODO: Should we return some ENUM here?
    if (channelObj == NULL) {
        return;
    }

    // TODO: channel_msg also includes arduino_id and sensor_id. Can we validate this before modifying the current_value?

    // Message type checking
    // Need to double check what typeid.name() returns for double and arrays
    string sensorType(typeid(msg->sensor_value).name());

    // d = double and i = int
    if (sensorType == "d"|| sensorType == "i") {
        channelObj->current_value = msg->sensor_value;
        time(&channelObj->last_comm_time);

        // Debugging purposes
        cout << "Current Value: " << channelObj->current_value << endl;
        cout << "Time received: " << channelObj->last_comm_time << endl;
    } else {
        // Returning some string or gibberish
        channelObj->current_value = -1;
    }
}

double Channel::getCurrentValue() {
    // TODO: Do we need to guard this with a semaphore?
    return this->current_value;
}

channel_msg_subscription_t* Channel::subscribeToChannel(zcm_t* zcm) { 
    return channel_msg_subscribe(zcm, this->channel_name.c_str(), &callbackHandler, NULL);
}