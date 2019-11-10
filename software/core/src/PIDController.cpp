//#include <lcm/lcm-cpp.hpp>
#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include <stdio.h>
#include "../include/PIDController.hpp"

PIDController::PIDController(const int pin, const int initialState, const int totalStates, double *Kp, double *Ki, double *Kd, 
                             double* Setpoint, int* POn, int* Direction, int* Mode, double* upperlimit, double* lowerlimit) :
                            
    Controller(&Input, &Output, goal, 0.0, 0.0, 0.0, P_ON_E, DIRECT)
                             
{
    if (pin > 0) {
        
        controller_pin = pin;
        Input = analogRead(controller_pin);
    }
    // TODO: error handling inside constructor

    if (totalStates >= 1) { TotalStates = totalStates;}
    else {/* TODO: ERROR HANDLING*/}

    kp = new double[totalStates];
    ki = new double[totalStates];
    kd = new double[totalStates];
    setpoint = new double[totalStates];
    PoN =  new int[totalStates];
    dir =  new int[totalStates];
    PIDMode = new int[totalStates];
    upperLimit = new double[totalStates];
    lowerLimit = new double[totalStates];

    for (int i = 0; i < totalStates; i++) {
        
        if (Kp[i] >= 0 && Ki[i] >= 0 && Kd >= 0) {

            kp[i] = Kp[i];
            ki[i] = Ki[i];
            kd[i] = Kd[i];
        
        } else {/*TODO: ERROR HANDLE*/}

        setpoint[i] = Setpoint[i];

        if (POn[i] == P_ON_E || POn[i] == P_ON_M) {

            PoN[i] = POn[i];

        } else {/*TODO: ERROR HANDLE */}

        if (Direction[i] == DIRECT || Direction[i] == REVERSE) {

            dir[i] = Direction[i];

        } else {/*TODO: ERROR HANDLE */}

        if (Mode[i] == AUTOMATIC || Mode[i] == MANUAL) {

            PIDMode[i] = Mode[i];

        } else {/*TODO: ERROR HANDLE */}

        upperLimit[i] = upperlimit[i];
        lowerLimit[i] = lowerlimit[i];

    }
    
    // Set to Current State
    this->StateChange(initialState);
    // TODO: error handling
}

PIDController::~PIDController() {

    delete kp;
    delete ki;
    delete kd;
    delete setpoint;
    delete PoN;
    delete dir;
    delete PIDMode;
    delete upperLimit;
    delete lowerLimit;
}

int PIDController::setpin(const int pin) {

    if (pin > 0) {
        controller_pin = pin;
        return 0;

    } else {return -1;}
}

int PIDController::getpin() {

    return controller_pin;
}

int PIDController::StateChange(int NewState) {
        
    if (NewState >= TotalStates || NewState < 0) {return -1;}

    currentState = NewState;

    // Update Controller PID
    goal = &(setpoint[currentState]); // PID Functions via a pointer reference to goal
    Controller.SetTunings(kp[currentState], ki[currentState], kp[currentState], PoN[currentState]);
    Controller.SetControllerDirection(dir[currentState]);
    Controller.SetMode(PIDMode[currentState]);
    Controller.SetOutputLimits(lowerLimit[currentState], upperLimit[currentState]);

    return 0;
}

int PIDController::update() { // TODO: Add error checking to return error code on problem

    if (controller_pin != -1) {
            
        Input = analogRead(controller_pin);
        Controller.Compute();
        analogWrite(controller_pin, Output);
    }
    return 0;
}