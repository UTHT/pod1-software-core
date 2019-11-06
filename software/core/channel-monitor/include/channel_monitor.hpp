#pragma once

using namespace std;

#include <string>
#include <vector>
#include <lcm/lcm-cpp.hpp>
#include "../helper/enums.hpp"
//#include "DataReader"

// Temporary class (for now)
class DataReader {
    public:
        double sensorValue;
};

class ChannelMonitor{

    private:    
        string channel_name;
        DataReader channel_data;

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

        // We can use the default destructor
        //~ChannelMonitor(){}

        // Instead of passing the sensor value to the function, it can get the sensor
        // value directly from the private class member. 
        // May need to check for sync issues in this case
        bool isSensorValueInRange(double channel_sensor_value) {
            return (channel_sensor_value >= min_accepted_value) && (max_accepted_value >= channel_sensor_value);
        }

        // Check the channel value
        channelStatus check(){
            channelStatus status = good;

            // If the sensor value from the channel does not exist or is 0 
            if(!channel_data.sensorValue || channel_data.sensorValue == 0) {
                status = noValue;
            } else if(!isSensorValueInRange(channel_data.sensorValue)) {
                status = outOfRange;
            }

            return status;
        }

        // Are we publishing this into the channel? Or just to other classes that may 
        // need this information
        void publish(){

        }
}