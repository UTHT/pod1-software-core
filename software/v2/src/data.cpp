#include "data.hpp"

#include <string>
#include <iostream>

std::string Sensor::bundleSensor(){
    std::string json = "";
    std::string letters[3] = {"x", "y", "z"};
    
    if (values.size() == 1){
        json += "{\"name\": \"" + name + "\", " + "\"value\": " + std::to_string(values[0]) + "}";
        return json;
    }

    for (int i = 0; i < values.size(); i++){
        json += "{\"name\": \"" + name + "_" + letters[i] + "\", \"value\": " + std::to_string(values[i]) + "},";
    }
    json.pop_back();
    return json;
    
}

std::string Data::bundleStatus(){
    std::string json = "\"status\" [";
    
    json += "{ \"name\": \"" + temp_front.name + "\", \"value\": " + std::to_string(int(temp_front.status)) + "},";
    json += "{ \"name\": \"" + temp_center.name + "\", \"value\": " + std::to_string(int(temp_center.status)) + "},";
    json += "{ \"name\": \"" + temp_back.name + "\", \"value\": " + std::to_string(int(temp_back.status)) + "},";
    json += "{ \"name\": \"" + accel.name + "\", \"value\": " + std::to_string(int(accel.status)) + "},";
    json += "{ \"name\": \"" + velocity.name + "\", \"value\": " + std::to_string(int(velocity.status)) + "},";
    json += "{ \"name\": \"" + velocity_inv.name + "\", \"value\": " + std::to_string(int(velocity_inv.status)) + "},";
    json += "{ \"name\": \"" + DC_curr.name + "\", \"value\": " + std::to_string(int(DC_curr.status)) + "},";
    json += "{ \"name\": \"" + pressure_1000.name + "\", \"value\": " + std::to_string(int(pressure_1000.status)) + "},";
    json += "{ \"name\": \"" + pressure_200_1.name + "\", \"value\": " + std::to_string(int(pressure_200_1.status)) + "},";
    json += "{ \"name\": \"" + pressure_200_2.name + "\", \"value\": " + std::to_string(int(pressure_200_2.status)) + "},";
    json += "{ \"name\": \"" + gap_height.name + "\", \"value\": " + std::to_string(int(gap_height.status)) + "},";
    json += "{ \"name\": \"" + position.name + "\", \"value\": " + std::to_string(int(position.status)) + "},";
    json += "{ \"name\": \"" + vibration.name + "\", \"value\": " + std::to_string(int(vibration.status)) + "}";

    return json;
}

std::string Data::bundleData(){
    //initial
    std::string json = "{\"eventType\": \"relay\",\"clientType\": \"odroid\",\"data\": {\"temperature\": [";
    //temperature
    //might add canbus temp
    json += temp_front.bundleSensor() + "," + temp_center.bundleSensor() + "," + temp_back.bundleSensor();
    json += "],";
    //pressure
    json += "\"pressure\": [";
    json += pressure_1000.bundleSensor() + "," + pressure_200_1.bundleSensor() + "," + pressure_200_2.bundleSensor();
    json += "],";
    //acceleration
    json += "\"acceleration\": [";
    json += accel.bundleSensor();
    json += "],";
    //velocity
    //might add inverter velocity
    json += "\"velocity\": [";
    json += velocity.bundleSensor() + "," + velocity_inv.bundleSensor();
    json += "],";
    //position
    json += "\"position\": [";
    json += position.bundleSensor();
    json += "],";
    //DC current
    json += "\"DC_current\": [";
    json += DC_curr.bundleSensor();
    json += "],";
    //gap height
    json += "\"gap_height\": [";
    json += gap_height.bundleSensor();
    json += "],";
    //vibrations
    json += "\"vibrations\": [";
    json += vibration.bundleSensor();
    json += "],";
    //curr state and previous state
    json += "\"state\": [";
    json += "{ \"name\": \"curr_state\", \"value\": " + std::to_string(curr_state) + "}, {\"name\": \"prev_state\",\"value\":" + std::to_string(prev_state) + " }";
    json += "],";
    //status
    json += bundleStatus();
    json += "] } }";

    return json;
}
