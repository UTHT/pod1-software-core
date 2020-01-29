#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include <stdio.h>
#include <vector>

#include "../include/State.hpp"
#include "../include/Controller.hpp"
#include "../include/BrakeController.hpp"
#include "../include/helper/enums.hpp"
#include "../include/helper/IOPin.hpp"

BrakeController::BrakeController(const struct IOPin io_pin,
                                 const States current_state,
                                 const std::vector<Channel> channels) :
    
    Controller(io_pin, current_state, channels)

{}

int BrakeController::run() {

    // code
    return 0;
}

bool BrakeController::shutdown() {

    //code

}