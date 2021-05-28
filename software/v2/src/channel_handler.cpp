#include <iostream>
#include <fstream>
#include <string>

#include "channel_handler.hpp"
#include "data.hpp"

ChannelHandler::ChannelHandler(){
    
}

void ChannelHandler::updateData(){
    data.temp_center.values[0] = rand() % 50;
} 

void ChannelHandler::updateComm(){
    int x;

    std::cin >> x;

    switch(x){
        case 0: data.curr_command = NO_comm; break;
        case 1: data.curr_command = LOCK_comm; break;
        case 2: data.curr_command = ARM_comm; break;
        case 3: data.curr_command = DRIVE_comm; break;
        case 4: data.curr_command = ESTOP_comm; break;
        default: data.curr_command = NO_comm; break;
    }
}