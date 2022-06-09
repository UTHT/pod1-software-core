#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "channel_handler.hpp"
#include "data.hpp"

std::string line;
std::ifstream sensor_file("sensor_data.csv");

ChannelHandler::ChannelHandler() {
    
}

std::string ChannelHandler::sendBundle(){
    // implement web socket connection
    return data.bundleData();
}

void ChannelHandler::updateData(){
    if (std::getline(sensor_file, line)) {
        std::istringstream iss(line);
        std::string token;
        float data_values [4];
        int i = 0;
        while (std::getline(iss, token, ',')) {   
            data_values[i] = std::stof(token);
            i++;
        }
        
        data.temp_center.values[0] = data_values[1];
        data.DC_curr.values[0] = data_values[2];
        data.pressure_200_1.values[0] = data_values[3];
        
    }
} 

void ChannelHandler::updateComm(){
    int x;

    std::cin >> x;

    switch(x){
        case 0: data.curr_command = NO_comm; break;
        case 1: data.curr_command = ON_comm; break;
        case 2: data.curr_command = DRIVE_comm; break;
        case 3: data.curr_command = BRAKE_comm; break;
        default: data.curr_command = NO_comm; break;
    }
}