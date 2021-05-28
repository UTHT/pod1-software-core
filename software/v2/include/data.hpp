#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include "en.hpp"

struct Sensor {
    std::string name;
    std::vector<float> values;
    bool status;
    std::string bundleSensor();
  
    Sensor(std::string n){name = n; values.push_back(0.0); status = true;}
    Sensor(std::string n, std::vector<float> v, bool st){ name = n; values = v; status = st;}
};

struct Data {
    struct Sensor temp_front = Sensor("temp_front");
    struct Sensor temp_center = Sensor("temp_center");
    struct Sensor temp_back = Sensor("temp_back");
    struct Sensor accel = Sensor("accel", std::vector<float> (3, 0.0), true);
    struct Sensor velocity = Sensor("velocity", std::vector<float> (3, 0.0), true);
    struct Sensor velocity_inv = Sensor("velocity_inv");
    struct Sensor DC_curr = Sensor("DC_curr");
    struct Sensor pressure_1000 = Sensor("pressure_1000");
    struct Sensor pressure_200_1 = Sensor("pressure_200_1");
    struct Sensor pressure_200_2 = Sensor("pressure_200_2");
    struct Sensor gap_height = Sensor("gap_height");
    struct Sensor position = Sensor("position", std::vector<float> (3, 0.0), true);
    struct Sensor vibration = Sensor("vibration");
    state_t curr_state = OFF;
    state_t prev_state = OFF;
    comm_t curr_command = NO_comm;
    std::string bundleData();
};

extern struct Data data;

// struct sesnsor and struct data -> value, status, name
// func to pack data

// data will have all sensors

// sensor

// data class has all the sensors 
// data class also has state
// func: bundles data json
// 

#endif