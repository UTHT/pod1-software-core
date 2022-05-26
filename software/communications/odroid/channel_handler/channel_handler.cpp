// Implementation of channel handler
#include "channel_handler.hpp"
#include "json.hpp"

bool subscribeToChannels() {
    populate_channel_map();

    // Subscribe to each channel in the channel_map
    for (std::pair<string, Channel*> element : channel_map) {
        element.second -> subscribeToChannel();
    }

    return true;
}

void populate_channel_map() {

    //Code to open and read from json file channels.json
    std::ifstream i ("channels.json");
    nlohmann::json j;
    i>>j;        

    //Iterate through json object and assign values accessed through json type
    for (int x = 0; x < j["channels"].size(); x++){       

        std::string name = j["channels"][x]["sensor"];
        std::string port = j["channels"][x]["serial_port"];
        std::string arduino_id = j["channels"][x]["arduino_id"];
        double min_value = j["channels"][x]["min_value"];
        double max_value = j["channels"][x]["max_value"];

        Channel *temp = new Channel(name, port, arduino_id, min_value, max_value);
        
        // TODO: Implement add_to_channel()
        // add_to_channel(temp);
    }    
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