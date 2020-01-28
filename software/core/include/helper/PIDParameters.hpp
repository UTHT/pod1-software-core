#ifndef PIDPARAMETERS_H
#define PIDPARAMETERS_H

#include "PID_v1.h"

struct PIDParameters {

    // default values
    double Kp = 0.0;             // Proportional
    double Ki = 0.0;             // Integral
    double Kd = 0.0;             // Derivative
    double Setpoint = 0.0;       // Desired Reading Goal
    int PoN = P_ON_E;            // Classical Proportional on Error System
    int Direction = DIRECT;      // DIRECT control (alternative is REVERSE control...proportional vs inversely proportional)
    int Mode = MANUAL;           // Initialized Controller is DISABLED
    
    // entire output range
    double upperLimit = 255.0;
    double lowerLimit = 0.0;
};

#endif
