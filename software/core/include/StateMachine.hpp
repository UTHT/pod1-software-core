#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "helper/enums.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class StateMachine {
  private:
    States current_state;
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

  public:
  StateMachine(const fs::path &config_path);
  ~StateMachine();
  void run();
};

#endif
