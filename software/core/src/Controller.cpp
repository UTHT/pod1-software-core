#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Controller.hpp"
#include "PIDController.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "helper/PIDParameters.hpp"


Controller::Controller(
    const struct IOPin io_pin,
    const States current_state,
    const std::vector<Channel> channels) : low_level_controls(io_pin, /*pid_struct*/)
{

    this->current_state = current_state;
    this->io_pin = io_pin;
    this->channels = channels;

    // Communications Object Declarations, etc
}

void Controller::state_change(const States change_to) {

  this->current_state = change_to;
}

// run() & shutdown() removed as Controller is the base class
// they will be defined in the derived motor & brake classes
// specific to their functionality


