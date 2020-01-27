#include <stdexcept>
#include <fstream>

#include "StateMachine.hpp"


StateMachine::StateMachine(const fs::path &config_file){
  if (!fs::exists(config_file))
    throw std::invalid_argument("StateMachine: The file config path does not exist.");
  if (config_file.extension() != ".yaml")
    throw std::invalid_argument("StateMachine: The file config path must be a '.yaml' file");
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

  // state_channel = Channel("");
  // location_channel = Channel("");
  // imu_channel = Channel("");
  // motor_temp_channel = Channel("");
  // front_wheel_temp_channel = Channel("");
  // battery_temp_channel = Channel("");
  // battery_level_channel = Channel("");
  // gap_height_front_channel = Channel("");
  // gap_height_rear_channel = Channel("");
  // vibration_channel = Channel("");
  // pressure_reserve_channel = Channel("");
  // pressure_secondary_channel = Channel("");
}

StateMachine::~StateMachine(){
}

void StateMachine::get_data(){
}

void StateMachine::run(){

  while (true){
    // get_data();
    if(current_state == OFF){
    }
    else if(current_state == ESTOP){
    }
    else if(current_state == DEBUG){
    }
    else if(current_state == COMMS_CHECK){
    }
    else if(current_state == SYS_CHECK){
    }
    else if(current_state == LOCK){
    }
    else if(current_state == ARM){
    }
    else if(current_state == DRIVE){
    }
    else if(current_state == BRAKE){
    }
    else{
      throw "Unknown state in state machine";
    }
  }
}
