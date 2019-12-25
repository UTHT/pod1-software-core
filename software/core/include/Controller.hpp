#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Controller.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
// #include "../lib/Arduino-PID-Library/PID_v1.h"

class Controller {
  private:
    // defined in enums
    struct IOPin io_pin;
    States current_state;
    std::vector<Channel> channels;

  public:
    
    Controller(const struct IOPin io_pin,
               const States current_state,
               const std::vector<Channel> channels);

    virtual ~Controller();
    int state_change(const States change_to);
    // Run through list of channels for updated sensor values and command instructions
    virtual int run() = 0;
   // ESTOP command
    virtual bool shutdown() = 0;
};
#endif
