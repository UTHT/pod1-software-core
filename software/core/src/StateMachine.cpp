#include <fstream>
#include <stdexcept>
#include "StateMachine.hpp"

StateMachine::StateMachine(const fs::path &config_path){
  if (!fs::exists(config_path))
    throw std::invalid_argument("StateMachine: The file config path does not exist.");
  current_state = OFF;
  max_distance = 0;
  max_motor_temperature = 0;
  max_front_wheel_temperature = 0;
  max_battery_temperature = 0;
  min_battery_level = 0;
  min_gap_height_front = 0;
  min_gap_height_rear = 0;
  max_vibration = 0;
  min_air_pressure_reserve = 0;
  min_air_pressure_secondary = 0;
}
StateMachine::~StateMachine(){
}
void StateMachine::run(){
  while (true){
  }
}
