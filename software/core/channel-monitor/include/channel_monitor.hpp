#pragma once

using namespace std;

#include <string>
#include <vector>
#include "../helper/enums.hpp"
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
        ChannelMonitor(double minAcceptedValue, double maxAcceptedValue, double minAcceptedFrequency, double maxAcceptedFrequency) {
            min_accepted_value = minAcceptedValue;
            max_accepted_value = maxAcceptedValue;
            min_accepted_frequency = minAcceptedFrequency;
            max_accepted_frequency = maxAcceptedFrequency;
        };

        bool isSensorValueInRange(double channel_sensor_value) {
            return (channel_sensor_value >= min_accepted_value) && (max_accepted_value >= channel_sensor_value);
        }

        // Check the channel value. Vector if there are multiple problems
        vector<channelStatus> check(){
            vector<channelStatus> statusOfChannel;
            //channelStatus status = functioning;

            // Check the sensor value
            if(!channel_data.sensorValue || channel_data.sensorValue == 0) {
                statusOfChannel.push_back(noValue);
            } else if(!isSensorValueInRange(channel_data.sensorValue)) {
                statusOfChannel.push_back(outOfRange);
            }

            // Check the frequency
            if(channel_data.frequencyValue > max_accepted_frequency) {
                statusOfChannel.push_back(highFrequency);
            } else if(channel_data.frequencyValue < max_accepted_frequency) {
                statusOfChannel.push_back(lowFrequency);
            }

            if(statusOfChannel.empty()) {
                statusOfChannel.push_back(functioning);
            }

            return statusOfChannel;
        }

        // Will edit this based on the Channel class implementation
        void publish(){

        }
}