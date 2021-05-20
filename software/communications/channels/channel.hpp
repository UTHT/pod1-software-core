#include <iostream>
#include <string>
#include "../libraries/zcm_types/src/zcm_msg.h"
#include "enums.hpp"

using namespace std;

class Channel {

    private:
        string channel_name;
        double current_value;
        double min_value;
        double max_value;
        time_t last_comm_time; 
        // some timestamp variable

        void callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const zcm_msg* msg, void* user);

    public:
        Channel(string channel_name, double min_value, double max_value);
        double getCurrentValue();
        int subscribeToChannel(zcm_t* zcm); 
        int validateCurrentValue();
        
};