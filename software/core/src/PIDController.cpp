//#include <lcm/lcm-cpp.hpp>
#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "PIDController.hpp"


PIDController::PIDController(const struct IOPin io_pin,
                             const STATES current_state,
                             const int total_states,
                             const std::vector<double> Kp,
                             const std::vector<double> Ki,
                             const std::vector<double> Kd,
                             const std::vector<double> Setpoint,
                             const std::vector<int> POn,
                             const std::vector<int> Direction,
                             const std::vector<int> Mode,
                             const std::vector<double> upperLimit,
                             const std::vector<double> lowerLimit) :
                            
    Controller(&Input, &Output, goal, 0.0, 0.0, 0.0, P_ON_E, DIRECT)
                             
{   
    this->setpin(io_pin);
    this->Input = analogRead(io_pin.pin_number);
    
    // Set to Current State
    this->state_change(current_state);

    // TODO: error handling inside constructor
    if (!(total_states == Kp.size() == Ki.size() == Kd.size() == 
          Setpoint.size() == POn.size() == Direction.size() == 
          Mode.size() == upperLimit.size() == lowerLimit.size())) {

        /*TODO: ERROR HANDLE*/
    }

    for (int i = 0; i < total_states; i++) {
        
        if (Kp[i] < 0 || Ki[i] < 0 || Kd[i] < 0) {
            /*TODO: ERROR HANDLE*/
        }

        if (POn[i] != P_ON_E && POn[i] != P_ON_M) {

            /*TODO: ERROR HANDLE */
        }

        if (Direction[i] != DIRECT && Direction[i] != REVERSE) {
            
            /*TODO: ERROR HANDLE */
        }

        if (Mode[i] == AUTOMATIC || Mode[i] == MANUAL) {
            
            /*TODO: ERROR HANDLE */
        }
    }

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->Setpoint = Setpoint;
    this->PoN = POn;
    this->Direction = Direction;
    this->Mode = Mode;
    this->upperLimit = upperLimit;
    this->lowerLimit = lowerLimit;
    this->goal = &(Setpoint[current_state]);
}

PIDController::PIDController(const PIDController & src) = default;

PIDController::~PIDController() = default;

int PIDController::setpin(const struct IOPin io_pin) {
    
    if (io_pin.pin_number < 0) {
        return -1;
    }
    this->io_pin = io_pin;
    return 0;
}

struct IOPin PIDController::getpin() {

    return this->io_pin;
}

void PIDController::state_change(const STATES change_to) {
        
    current_state = change_to;

    // Update Controller PID
    goal = &(Setpoint[current_state]); // PID Functions via a pointer reference to goal
    Controller.SetTunings(Kp[current_state], Ki[current_state], Kp[current_state], PoN[current_state]);
    Controller.SetControllerDirection(Direction[current_state]);
    Controller.SetMode(Mode[current_state]);
    Controller.SetOutputLimits(lowerLimit[current_state], upperLimit[current_state]);
}

bool PIDController::update() { // TODO: Add error checking to return error code on problem

    bool status;        
    Input = analogRead(io_pin.pin_number);
    status = Controller.Compute();
    analogWrite(io_pin.pin_number, Output);
    return status;
}