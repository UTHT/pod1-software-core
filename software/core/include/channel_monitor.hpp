#ifndef CHANNEL_MONITOR
#define CHANNEL_MONITOR
#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"
#include <string>

class ChannelMonitor {

    std::string channel_name;
    
    public:
        ChannelMonitor();
        ~ChannelMonitor();

        void check();
        void publish();
};

#endif