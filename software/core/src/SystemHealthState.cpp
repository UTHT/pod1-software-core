#include "SystemHealthState.hpp"

SystemHealthState::SystemHealthState(States name) : State(name){

}

SystemHealthState::~SystemHealthState(){
}

States SystemHealthState::run(){
  //if k=n,Go to SystemHealthCheck
  //state = Arm
  //else
  //state = Debug
  return SYS_CHECK;
}

