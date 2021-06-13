
#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>
#include <ctime> 
#include <mutex>
#include <vector>

#include <linux_cobs_serial_transport.hpp>
#include <channel_array_msg.h>
#include "enums.hpp"

using namespace std;

class Channel {
    private:
        string channel_name;
        string serial_port;
        zcm_t* zcm;
        mutex lock;

        vector<double> current_values;
        double min_value;
        double max_value;
        time_t last_comm_time; 

        static void callbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_array* msg, void* user);

    public:
        Channel(string channel_name, string serial_port, double min_value, double max_value);

        vector<double> getCurrentValues();
        zcm_t* getZCM();
        string getChannelName();

        channel_array_subscription_t* subscribeToChannel(); 
        int validateCurrentValue();
};

// The channel handler needs to populate this channel_map
extern unordered_map<string, Channel*> channel_map;

#endif