#include "channel.hpp"
#include "enums.hpp"
//type checking
#include <typeinfo>
#include <ctime> 


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

void Channel::callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const zcm_msg* msg, void* user) {
    // Guarded by a semaphore

    // TODO: zcm_msg also includes arduino_id and sensor_id. Can we validate this before modifying the current_value?

    // message type checking
    // Need to double check what  typeid.name() returns for double and arrays
    if (typeid(msg->data_value).name() == "double" || typeid(msg->data_value).name() == "int") {
        this->current_value = msg->data_value;
        time(&this->last_comm_time);
    } else {
        //returning some string or gibberish
        this->current_value = -1;
    }
}

double Channel::getCurrentValue() {
    // TODO: Do we need to guard this with a semaphore?
    return this->current_value;
}

int Channel::subscribeToChannel(zcm_t* zcm) {  
    return zcm_msg_subscribe(zcm, this->channel_name, &this->callbackHandler, NULL);
}