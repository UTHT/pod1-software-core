
#ifndef LOCK_STATE_HPP
#define LOCK_STATE_HPP

#include "State.hpp"
#include "Channel.hpp"


struct LCMTypeLaunchTrigger{
  bool state = false;

  LCMTypeLaunchTrigger(bool state = false){
    this->state = state;
  }
};


class LockState: public State{

  private:
    States name;
    Channel* launch_trigger_channel_ptr;
    LCMTypeLaunchTrigger launch_trigger;

  public:

  //default constructor
  LockState();

  //primary constructor
  LockState(States name);

  //check channels
  States run();

  //destructor
  ~LockState();
};

#endif
