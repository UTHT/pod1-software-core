#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
// #include "../lib/Arduino-PID-Library/PID_v1.h"

// TODO: Need to add functionality if sensors measurements occur with the same Arduino
// Sensor class?

class Controller {
  private:
    // defined in enums
    struct IOPin io_pin;
    STATES current_state;
    int total_states;
    std::vector<Channel> channels;

  public:
    Controller(const struct IOPin io_pin,
               const STATES current_state,
               const int total_states,
               const std::vector<Channel> channels);
    virtual ~Controller();
    int state_change(const STATES change_to);
    // Run through list of channels for updated sensor values and command instructions
    virtual int run();
   // ESTOP command
    virtual bool shutdown();
};
#endif