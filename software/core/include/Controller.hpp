#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Channel.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
// #include "PID_v1.h"

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
    void state_change(const States change_to);
    // Run through list of channels for updated sensor values and command instructions
    virtual int run() = 0;
   // ESTOP command
    virtual bool shutdown() = 0;
};

class Controller : private BrakeController {
   private:
   struct unint8_t Io_pin{
     unint8_t LEDpin;
     unint8_t motorPin;
   }
   unint8_t value;
   States current_state;

   public:
   BrakeController(unint8_t LEDpin, unint8_t motorPin, unint8_t value);
   bool shutdown(unint8_t value);
};
#endif
