#ifndef PIDController_h
#define PIDController_h
#include <stdio.h>
#include "../lib/Arduino-PID-Library/PID_v1.h"

class PIDController {
    private:
        
        int currentState = 0;
        int TotalStates = 0;
        
        int controller_pin = -1; // Default value
        double Input = 0;
        double Output = 0;
        double* kp = nullptr;
        double* ki = nullptr;
        double* kd = nullptr;
        double* setpoint = nullptr;
        int* PoN = nullptr;
        int* dir = nullptr;
        int* PIDMode = nullptr;
        double* upperLimit = nullptr;
        double* lowerLimit = nullptr;

        double* goal = &(setpoint[currentState]);

        // PID Controller
        PID Controller;

    public:

        PIDController(const int pin, const int initialState, const int totalStates, double Kp[], double Ki[], double Kd[], 
                             double Setpoint[], int POn[], int Direction[], int Mode[], double upperlimit[], double lowerlimit[]);

        ~PIDController();

        // Update State Value upon state changes
        int StateChange(int NewState);

        int setpin(int pin);

        int getpin();

        int update();
};
#endif