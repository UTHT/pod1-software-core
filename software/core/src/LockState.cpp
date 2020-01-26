
#include "LockState.hpp"

//default constructor
LockState::LockState():State(){}

//[call the same systems check executed within the 'SYS_CHECK' state]
// >>>
bool run_systems_diagnostic_check(){
  return true;
}
// <<<


//primary constructor
LockState::LockState(States name):State(name){

  this->name = name;
  this->launch_trigger_channel_ptr = new Channel("primary_launch_trigger");
  this->launch_trigger = LCMTypeLaunchTrigger();
}


//function to request data from States
States LockState::run(){

  // >>> [Uncomment Once 'handle' implemented within channel class]
  // this->launch_trigger_channel_ptr->handle(this->launch_trigger);
  // <<<

  // TODO : while True or as is
  if (this->launch_trigger.state){

    //run systems diagnostic check,
    //if successful proceed to 'ARM', else 'DEBUG' state
    if (run_systems_diagnostic_check()){
      return ARM;
    }
    return DEBUG;
  }
  return LOCK;
}


//destructor
LockState::~LockState(){
  delete this->launch_trigger_channel_ptr;
}
