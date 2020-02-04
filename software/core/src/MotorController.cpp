#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include <stdio.h>
#include <vector>

#include "../include/State.hpp"
#include "../include/Controller.hpp"
#include "../include/MotorController.hpp"
#include "../include/helper/enums.hpp"
#include "../include/helper/IOPin.hpp"


MotorController::MotorController(const struct IOPin io_pin,
                                 const States current_state,
                                 const std::vector<Channel> channels) :
    
    Controller(io_pin, current_state, channels)

{}

int MotorController::run() {

    switch (Controller::current_state)
    {
    case ESTOP:
        shutdown();
        break;

    case OFF:
        shutdown();
        break;

    case DEBUG:
        /* code */
        break;

    case COMMS_CHECK:
        /* code */
        break;

    case SYS_CHECK:
        /* code */
        break;

    case LOCK:
        /* code */
        break;

    case ARM:
        /* code */
        break;

    case DRIVE:
        /* code */
        break;

    case BRAKE:
        /* code */
        break;

    default:
        break;
    }

    // code
    return 0;
}

void MotorController::shutdown() {

    Controller::low_level_controls.shutdown();
}


void MotorController::determine_pid_parameters(struct State_Transition & nextInternalState, struct Pod_Data & currentStatus){

    // default values
    double Kp = 0.0;             // Proportional
    double Ki = 0.0;             // Integral
    double Kd = 0.0;             // Derivative
    double Setpoint = 0.0;       // Desired Reading Goal
    int Direction = DIRECT;      // DIRECT control (alternative is REVERSE control...proportional vs inversely proportional)
    int Mode = MANUAL;           // Initialized Controller is DISABLED

    //determine direction from sign of speed
    this->pid_parameters.direction = (nextInternalState.speed > 0.0) ? 0 : 1; 

    this->pid_parameters.Setpoint = (nextInternalState.speed > 0.0) ? nextInternalState.speed : 0.0;

    // determine mode based on sign of speed...depends on regen
    this->pid_parameters.Mode = (nextInternalState.speed > 0.0) ? 1 : 0;

}