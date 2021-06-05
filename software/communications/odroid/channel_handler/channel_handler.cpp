// Implementation of channel handler
#include "channel_handler.hpp"

unordered_map<string, Channel*> channel_map;

bool subscribeToChannels() {
    populate_channel_map();

    // Subscribe to each channel in the channel_map
    for (std::pair<string, Channel*> element : channel_map) {
        element.second -> subscribeToChannel();
    }

    return true;
}

void add_to_channel(Channel* temp) {  
    channel_map[temp->getChannelName()] = temp;
}

void populate_channel_map() {
    Channel *temp = new Channel("temperature_1", "/dev/cu.usbmodem14501", 10, 30);
    Channel *temp1 = new Channel("voltage_1", "/dev/cu.usbmodem14501", 0, 5);
    Channel *temp2 = new Channel("resistance_1", "/dev/cu.usbmodem14501", 0, 10);

    add_to_channel(temp); 
    add_to_channel(temp1); 
    add_to_channel(temp2); 
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