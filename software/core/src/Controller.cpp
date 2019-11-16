#include "Controller.hpp"

Controller::Controller(){
}
Controller::Controller(
    const struct IOPin io_pin,
    const STATES current_state,
    const int total_states,
    const std::vector<Channel> channels){
}

Controller::~Controller(){
}
int Controller::state_change(const STATES change_to){
  /// REPLACE
  return 0;
  ///
}

int Controller::run(){
  /// REPLACE
  return 0;
  ///
}

bool Controller::shutdown(){
  /// REPLACE
  return true;
  ///
}
