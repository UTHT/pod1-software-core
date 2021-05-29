#include "channel.hpp"

Channel::Channel(string channel_name, string serial_port, double min_value, double max_value) {
    this->channel_name = channel_name;
    this->min_value = min_value;
    this->max_value = max_value;
    this->serial_port = serial_port;

    // Convert string to char*
    char* serial_port_c = new char[serial_port.length() + 1];
    strcpy(serial_port_c, serial_port.c_str());

    // The object should only be created if the serial_port is valid.
    // Otherwise, an error will be thrown.
    zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port_c);
    this->zcm = zcm_create_from_trans(linux_cobs_serial_transport);

    delete [] serial_port_c;

    // Defaulted this to the current time
    time(&this->last_comm_time);
}

// Should return an ENUM
int Channel::validateCurrentValue() {
    time_t current_comm_time; 

    // Update the current time 
    time(&current_comm_time); 

    this->lock.lock();
    // Get the difference between current time and the last communicated time
    double time_diff = difftime(current_comm_time, this->last_comm_time); 

    // Check time
    if (time_diff >= 60.0) {
        this->lock.unlock();
        return ChannelStatus::NO_COMMS;
    }

    // Check value within range
    if (this->current_value < this->min_value || this->current_value > this->max_value) {
        this->lock.unlock();
        return ChannelStatus::OUT_OF_RANGE;
    }

    // TODO: (Maybe) Check the frequency of data 
    // 1) What are the acceptable bounds?

    // Default return value
    this->lock.unlock();
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

    channelObj->lock.lock();

    // d = double and i = int
    if (sensorType == "d"|| sensorType == "i") {
        channelObj->current_value = msg->sensor_value;
        time(&channelObj->last_comm_time);

        // Debugging purposes
        cout << "Current Value: " << channelObj->current_value << endl;
        cout << "Time received: " << channelObj->last_comm_time << endl;
    } else {
        // Returning some string or gibberish
        // (It should never come her)
        channelObj->current_value = -1;
    }
    
    channelObj->lock.unlock();
}

double Channel::getCurrentValue() {
    this->lock.lock();
    double current_val = this->current_value;
    this->lock.unlock();

    return current_val;
}

zcm_t* Channel::getZCM() {
    return this->zcm;
}
string Channel::getChannelName() {
    return this->channel_name;
}

channel_msg_subscription_t* Channel::subscribeToChannel() { 
    return channel_msg_subscribe(this->zcm, this->channel_name.c_str(), &callbackHandler, NULL);
}