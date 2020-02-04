#ifndef PIDPARAMETERS_H
#define PIDPARAMETERS_H

#include "PID_v1.h"

struct PIDParameters {
    
    /*
    #define AUTOMATIC	1
    #define MANUAL	0
    #define DIRECT  0
    #define REVERSE  1
    #define P_ON_M 0
    #define P_ON_E 1
    */

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
