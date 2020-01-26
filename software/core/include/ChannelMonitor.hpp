#ifndef CHANNELMONITOR_H
#define CHANNELMONITOR_H


#include <string>
#include <vector>

#include "helper/enums.hpp"
#include "Channel.hpp"

class ChannelMonitor{
    private:
        // string channel_name;

        // Extra private members
        Channel channel;
        double min_value;
        double max_value;
        double min_rtt;
        double max_rtt;

    public:
        // For testing...
        ChannelMonitor();
        // Constructor to initialize the ChannelMonitor class
        ChannelMonitor(Channel channel,
                       double min_value, double max_value,
                       double min_rtt, double max_rtt);
        ~ChannelMonitor();

        int check();

        // Will edit this based on the Channel class implementation
        bool publish();
};

#endif
