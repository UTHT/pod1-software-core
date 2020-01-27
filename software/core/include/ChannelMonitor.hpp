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
      std::string channel_name;
        double min_value;
        double max_value;
        double min_rtt;
        double max_rtt;

    public:
        // Constructor to initialize the ChannelMonitor class
        ChannelMonitor(const std::string channel_name,
                       const double min_value, const double max_value,
                       const double min_rtt, const double max_rtt);

        ~ChannelMonitor();
        ChannelStatus check();

        // // Will edit this based on the Channel class implementation
        // bool publish();
};

#endif
