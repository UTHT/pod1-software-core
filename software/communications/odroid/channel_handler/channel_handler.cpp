// Implementation of channel handler
#include "channel_handler.hpp"
#include "nlohmann/json.hpp"

bool subscribeToChannels() {
    populate_channel_map();

    // Subscribe to each channel in the channel_map
    for (std::pair<string, Channel*> element : channel_map) {
        element.second -> subscribeToChannel();
    }

    return true;
}

void populate_channel_map() {
<<<<<<< HEAD

    //Code to open and read from json file channels.json
    std::ifstream i ("channels.json");
    nlohmann::json j;
    i>>j;        
    int x; 

    //Iterate through json object and assign values accessed through json type
    for( x = 0; x < j["channels"].size(); x++){       

        std::string name = j["channels"][x]["sensor"];
        std::string port = j["channels"][x]["serial_port"];
        double min_value = j["channels"][x]["min_value"];
        double max_value = j["channels"][x]["max_value"];

        Channel *temp = new Channel(name ,port,min_value ,max_value);
        add_to_channel(temp);

    }    

    // Channel *temp = new Channel("temperature_1", "/dev/cu.usbmodem14501", 10, 30);
    // Channel *temp1 = new Channel("voltage_1", "/dev/cu.usbmodem14501", 0, 5);
    // Channel *temp2 = new Channel("resistance_1", "/dev/cu.usbmodem14501", 0, 10);

    // add_to_channel(temp); 
    // add_to_channel(temp1); 
    // add_to_channel(temp2); 
=======
    Channel *temp = new Channel("temperature_1", "/dev/cu.usbmodem14501", 10, 30);
    Channel *temp1 = new Channel("voltage_1", "/dev/cu.usbmodem14501", 0, 5);
    Channel *temp2 = new Channel("resistance_1", "/dev/cu.usbmodem14501", 0, 10);
>>>>>>> Modified channel class for the new channel_array_msg zcm type. Defining the channel_map global var in channel.cpp now
}

int main() {
    subscribeToChannels();

    while (true) {
        for (std::pair<string, Channel*> element : channel_map) {
            zcm_handle_nonblock(element.second->getZCM());
            // ChannelStatus status = element.second -> validateCurrentValue();
        }
    }
}