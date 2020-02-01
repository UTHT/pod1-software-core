#ifndef BRAKE_STATE_HPP
#define BRAKE_STATE_HPP

#include "State.hpp"
#include "Channel.hpp"


struct LCMTypePosition{
  bool distance = 0;

  LCMTypePosition(int distance = 0){
    this->distance = distance;
  }
};

struct LCMTypeVelocity{
  int velocity = 0;

  LCMTypeVelocity(int velocity = 0){
    this->velocity = velocity;
  }
};

struct LCMTypeBrakeControl{
  bool enabled = false;

  LCMTypeBrakeControl(bool enabled = false){
    this->enabled = enabled;
  }
};


class BrakeState: public State{

  private:
    States name;
    Channel* position_channel_ptr;
    Channel* velocity_channel_ptr;
    Channel* brake_control_channel_ptr;

    LCMTypePosition position;
    LCMTypeVelocity velocity;

  public:

  BrakeState();
  ~BrakeState();


  /** Run brake operations if necessary. */  
  States run();

};

#endif