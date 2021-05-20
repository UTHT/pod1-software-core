// Implementation of channel handler
#include "channel_handler.hpp"
//type checking
#include <typeinfo>
#include <ctime> 

std::vector<Channel> subscribeToChannels() {

    std::vector<Channel> channels;
    Channel temp("temperature_1", 10, 30);
    Channel temp1("voltage_1", 0, 5);     
    Channel temp2("resistance_1", 0, 10); 

    // zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
    // zcm_t* zcm = zcm_create_from_trans(linux_cobs_serial_transport);
    zcm_t* arduino1;

    //temp.subscribeToChannel(); 


    channels.push_back(temp);
    channels.push_back(temp1);
    channels.push_back(temp2);

    for(int i = 0; i < channels.size(); i++) {
        channels[i].subscribeToChannel(zcm)
    }
    return channels;
}