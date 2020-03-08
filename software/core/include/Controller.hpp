#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <vector>
#include <string>

#include "State.hpp"
//Re-include once channel implementation finalized
//#include "Channel.hpp"
#include "PIDController.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "helper/PIDParameters.hpp"

//temporary Channel implementation to
//support controller channel data access
template <LCM_Type>
class Channel{

  private:
    LCM_Type* data = NULL;
    std::string channel_name;
  
  public:

    Channel(const std::string channel_name, LCM_Type* data){
      this->data_type    = data;
      this->channel_name = channel_name;
      //create lcm channel with channel name and data type
    }
    
    ~Channel(){
      //no need to deallocate 'LCM_Type'
    }

    void get(){
      //update lcm type from lcm channel
    }

    void publish(const LCM_Type & data){
      //publish updated data onto lcm channel
    }
};




//lcm type to indicate desired next motor state
struct State_Transition{

  double speed                   = 0;
  double max_transition_distance = 0;
  double min_transition_distance = 0;
  double max_transition_accel    = 0;
  double min_transition_accel    = 0;
};

struct Pod_Data {

  double instant_speed    = 0;
  double instant_accel    = 0;
  double instant_distance = 0;

};


class Controller {
  protected:
    // defined in enums
    struct IOPin io_pin;
    States current_state;
    std::vector<Channel> channels;
    PIDController low_level_controls;
    PIDParameters pid_parameters;

  public:
    
    Controller(const struct IOPin io_pin,
               const States current_state,
               const std::vector<Channel> channels);

    virtual ~Controller();
    void state_change(const States change_to);
    // Run through list of channels for updated sensor values and command instructions
    virtual int run() = 0;
   // ESTOP command
    virtual void shutdown() = 0;
    // Determines pid_parameters from currentStatus and desired nextStatus
    virtual void determine_pid_parameters(struct State_Transition & nextInternalState, struct Pod_Data & currentStatus) = 0; 
};
#endif
