#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "channel_handler.hpp"
#include "data.hpp"

std::string line;
std::ifstream sensor_file ("sensor_data.csv");

ChannelHandler::ChannelHandler() {
    
}

void ChannelHandler::updateData(){
    if (std::getline(sensor_file, line)) {
        std::istringstream iss(line);
        std::string token;
        float data_values [3];
        int i = 0;
        while (std::getline(iss, token, ',')) {   
            data_values[i] = std::stof(token);
            i++;
        }
        
        data.temp_center.values[0] = data_values[0];
        data.DC_curr.values[0] = data_values[1];
        data.pressure_200_1.values[0] = data_values[2];
        
    }
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