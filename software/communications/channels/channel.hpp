
#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>
#include <ctime> 

#include <linux_cobs_serial_transport.hpp>
#include <channel_msg.h>
#include "enums.hpp"

using namespace std;

class Channel {
    private:
        string channel_name;
        string serial_port;
        zcm_t* zcm;

        double current_value;
        double min_value;
        double max_value;
        time_t last_comm_time; 

        static void callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_msg* msg, void* user);

    public:
        Channel(string channel_name, string serial_port, double min_value, double max_value);

        double getCurrentValue();
        zcm_t* getZCM();

        channel_msg_subscription_t* subscribeToChannel(); 
        int validateCurrentValue();
};

// The channel handler needs to populate this channel_map
extern unordered_map<string, Channel*> channel_map;

#endif