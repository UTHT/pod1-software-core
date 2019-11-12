#pragma once

using namespace std;

#include <string>
#include <vector>
#include "/helper/enums.hpp"
//#include "Channel"

// Temporary class (for now)
// testing purposes
// class Channel {
//     public:
//         double sensorValue;
//         double frequencyValue;
// };

class ChannelMonitor{
    private:    
        string channel_name;

        // Extra private members
        Channel channel_data;
        double min_accepted_value;
        double max_accepted_value;
        double min_accepted_frequency;
        double max_accepted_frequency;
    
    public:
        // Constructor to initialize the ChannelMonitor class
        ChannelMonitor(double minAcceptedValue, double maxAcceptedValue, double minAcceptedFrequency, double maxAcceptedFrequency);

        // TODO : Check if this should be public?
        bool is_sensor_value_in_range(double channel_sensor_value);

        // Check the channel value. Vector if there are multiple problems
        vector<channelStatus> check();

        // Will edit this based on the Channel class implementation
        void publish();
}