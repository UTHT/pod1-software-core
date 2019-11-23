#if ARDUINO >= 100
  #include "Arduino.h"
#else
  //#include "WProgram.h"
#endif

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Controller.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"

Controller::Controller(
    const struct IOPin io_pin,
    const States current_state,
    const int total_states,
    const std::vector<Channel> channels)    
{

    if (total_states > 0) {
        
      this->current_state = current_state;
      this->total_states = total_states;
    }
    // TODO
    //else {ERROR HANDLING}

    this->io_pin = io_pin;
    this->channels = channels;

    // Communications Channel Reader Object Declarations, etc
}

Controller::~Controller() = default;

int Controller::state_change(const States change_to){
  

  this->current_state = change_to;
  return 0;
}

// run() & shutdown() removed as Controller is the base class
// they will be defined in the derived motor & brake classes
// specific to their functionality