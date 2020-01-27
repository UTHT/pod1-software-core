
#include "EstopState.hpp"

//primary constructor
EstopState::EstopState(States name):State(name){
  estop_info.raised_state_name = " ";
}


//function to request data from States
States EstopState::run(){
  //pass struct private member of class to LCM handler
  lcm_channel_handler(&(this->estop_info));
  return ESTOP;
}


//destructor
EstopState::~EstopState(){
}
