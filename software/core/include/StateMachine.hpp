#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include <filesystem>
#include <iostream>
#include <string>
#include <map>

#include "helper/enums.hpp"
#include "Channel.hpp"
#include "State.hpp"

namespace fs = std::filesystem;

class StateMachine {
  private:
    States current_state = OFF;
    std::map<std::string, State> states;

    double max_distance;
    double max_motor_temperature;
    double max_front_wheel_temperature;
    double max_battery_temperature;
    double min_battery_level;
    double min_gap_height_front;
    double min_gap_height_rear;
    double max_vibration;
    double min_air_pressure_reserve;
    double min_air_pressure_secondary;

    Channel state_channel;
    Channel location_channel;
    Channel imu_channel;
    Channel motor_temp_channel;
    Channel front_wheel_temp_channel;
    Channel battery_temp_channel;
    Channel battery_level_channel;
    Channel gap_height_front_channel;
    Channel gap_height_rear_channel;
    // Channel vibration_channel;
    Channel pressure_reserve_channel;
    Channel pressure_secondary_channel;

  public:
    StateMachine(const fs::path &config_file);
    ~StateMachine();
    // populate data from channels
    void get_data();
    void run();
};

#endif
