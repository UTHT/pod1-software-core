#include "channel.hpp"
//type checking
#include <typeinfo>
#include <time.h> 


Channel::Channel(string channel_name, double min_value, double max_value, time_t last_comm_time) {
    this->channel_name = channel_name;
    this->min_value = min_value;
    this->max_value = max_value;

    // TODO: Instead of passing a last_comm_time value to the constructor, can we default this value to NULL or like 0?
    this->last_comm_time = last_comm_time; 
}

// Should return an ENUM
int Channel::validateCurrentValue() {
    time_t current_comm_time; 
    double time_diff; 

    //update the current time 
    time(&current_comm_time); 

    //get the difference between current time and the last communicated time
    time_diff = difftime(current_comm_time, this->last_comm_time); 

    // Check time
    if (time_diff > 60.0) {
        // return a time ENUM for error checking 
    }


    // Check value within range
    if(this->current_value < this->min_value || this->current_value > this->max_value) {
        // THIS BAD - do some shit ???? o_O
    }
    // (Maybe) Check the frequency of data 


    // DEFAULT: return ALL_GOOD
}

void Channel::callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const zcm_msg* msg, void* user) {
    // Guarded by a semaphore

    // TODO: zcm_msg also includes arduino_id and sensor_id. Can we validate this before modifying the current_value?

    // message type checking
    // Need to double check what  typeid.name() returns for double and arrays
    if (typeid(msg->data_value).name() == "double" || typeid(msg->data_value).name() == "int" ) {
        this->current_value = msg->data_value;
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