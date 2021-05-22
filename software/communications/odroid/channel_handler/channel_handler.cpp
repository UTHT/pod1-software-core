// Implementation of channel handler
#include "channel_handler.hpp"
//type checking
#include <typeinfo>
#include <ctime> 

unordered_map<string, Channel*> channel_map;

/*
void createChannels() {
    // Read data from a database (mongoDB)
    // Sensor name, min value, max value, arduino id, sensor id

    for each row {
        Channel sensor(row.sensor_name, row.min_value ...)
        add this to the unordered map
    }
}
*/


bool subscribeToChannels(char *serial_port) {

    Channel *temp = new Channel("temperature_1", 10, 30);
    Channel *temp1 = new Channel("voltage_1", 0, 5);
    Channel *temp2 = new Channel("resistance_1", 0, 10);

    add_to_channel(temp); 
    add_to_channel(temp1); 
    add_to_channel(temp2); 

    /*
        try {
            zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
            zcm_t* zcm = zcm_create_from_trans(linux_cobs_serial_transport);
        } catch (Packet Error) {
            // Do something
        } catch (Another Error) {
            // 
        }
    */
    //char* serial_port = (char *) "/dev/cu.usbmodem14501";
    zcm_t* zcm = NULL;
    zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
    zcm = zcm_create_from_trans(linux_cobs_serial_transport);   
 
    // Subscribe to each channel in the channel_map
    for (std::pair<string, Channel*> element : channel_map) {
        element.second.subscribeToChannel(zcm)
    }

    return true;
}

void add_to_channel(Channel* temp) {  
    channel_map[temp->channel_name] = temp;
}


int main() {
    // 1) Define all the zcm transport layer objects and save them into a LOCAL unordered_map
    
    // 2) Create the channel objects and add it to the GLOBAL unordered map.
    //    a) Pass the zcm unordered_map to this function
    //    b) It may be easier for this function to subscribe to the channels too

    // 3) After subscribing, have a continuous for-loop (risky) that will call the channel -> validateCurrentValue() function
    //    a) Question: Let's say we get a ChannelStatus error ENUM, what should we do?
}