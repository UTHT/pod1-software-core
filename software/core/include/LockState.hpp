
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
    Channel* launch_trigger_channel_ptr;
    LCMTypeLaunchTrigger launch_trigger;

  public:
  //primary constructor
  LockState(States name);

  //destructor
  ~LockState();

  //check channels
  States run();

};

#endif
