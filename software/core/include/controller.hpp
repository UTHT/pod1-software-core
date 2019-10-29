#ifndef controller_h
#define controller_h
#include <iostream>
#include <stdio.h>
#include <vector>
#include "lib/Arduino-PID-Library/PID_v1.h"

// Need to add functionality if output measurements occur with the same Arduino
// Sensor class?

class Controller {
    private:

        // Current Controller State
        int State = 0;

        // Controller States, need to add other states
        #define ON 0
        #define RUN 6
        #define ESTOP 7
        #define TotalStates 8
        
        int time; // dummy variable to get Sampletime
        int Sampletime = 100; // Default value in Milliseconds
        
        int motor_input_pin = -1; // Default value to prevent access to motor PID
        double Motor_input = 0;
        double Motor_output = 0;
        const double Motor_P[TotalStates] = {5.6, 5.9, 4.8}; // dummy values
        const double Motor_I[TotalStates] = {5.6, 5.9, 4.8};
        const double Motor_D[TotalStates] = {5.6, 5.9, 4.8};
        const double Motor_Setpoint[TotalStates] = {4.2, 5.6, 7};
        const int Motor_POn[TotalStates] = {P_ON_M, P_ON_E};
        const int Motor_Direction[TotalStates] = {DIRECT, DIRECT};
        const int Motor_PID[TotalStates] = {AUTOMATIC, MANUAL};
        const double Motor_upperlimit[TotalStates] = {255, 255, 255};
        const double Motor_lowerlimit[TotalStates] = {0, 0, 0};

        double Motor_Kp = Motor_P[State];
        double Motor_Ki = Motor_I[State];
        double Motor_Kd = Motor_D[State];
        double Motor_setpoint = Motor_Setpoint[State];
        int Motor_PoN = Motor_POn[State];
        int Motor_Dir = Motor_Direction[State];
        int Motor_Mode = Motor_PID[State];
        double Motor_upper = Motor_upperlimit[State];
        double Motor_lower = Motor_lowerlimit[State];

        int brake_input_pin = -1; // Default value to prevent access to brake PID
        double Brake_input = 0;
        double Brake_output = 0;
        const double Brake_P[TotalStates] = {5.6, 5.9, 4.8}; // dummy values
        const double Brake_I[TotalStates] = {5.6, 5.9, 4.8};
        const double Brake_D[TotalStates] = {5.6, 5.9, 4.8};
        const double Brake_Setpoint[TotalStates] = {4.2, 5.6, 7};
        const int Brake_POn[TotalStates] = {P_ON_M, P_ON_E};
        const int Brake_Direction[TotalStates] = {REVERSE, REVERSE};
        const int Brake_PID[TotalStates] = {AUTOMATIC, MANUAL};
        const double Brake_upperlimit[TotalStates] = {0, 0, 255};
        const double Brake_lowerlimit[TotalStates] = {0, 0, 0};

        double Brake_Kp = Brake_P[State];
        double Brake_Ki = Brake_I[State];
        double Brake_Kd = Brake_D[State];
        double Brake_setpoint = Brake_Setpoint[State];
        int Brake_PoN = Brake_POn[State];
        int Brake_Dir = Brake_Direction[State];
        int Brake_Mode = Brake_PID[State];
        double Brake_upper = Brake_upperlimit[State];
        double Brake_lower = Brake_lowerlimit[State];

        // PID Controllers
        PID Motor;
        PID Brake;

        // Update Motor & Brake PID values when the state changes
        int StateChange(int NewState);

        // TODO: Decide
        // Temperature Control can be implemented as two PID loops working
        // against one another
        // Or as a seperate controller state, in which case the values below
        // wouldn't be required, instead they would be incorporated into ^
        // Until we decide I'm going to assume we stick with the motor and 
        // brake loop with different states to account for temperature, etc. 
        /*
        const double Temperature_P[TotalStates] = {5.6, 5.9, 4.8};
        const double Temperature_I[TotalStates] = {5.6, 5.9, 4.8};
        const double Temperature_D[TotalStates] = {5.6, 5.9, 4.8};
        */

        // Vector for Channels
        // Vector or set to store channels?????
        std::vector<std::string> Essential_Channels = {"IMPORTANT", "other bs"};
        std::vector<std::string> Motor_Channels = {"IMPORTANTbrake stuff", "other bs"};
        std::vector<std::string> Brake_Channels = {"IMPORTANTmotor stuff", "other bs"};

    public:

        Controller(int motor_pin, int brake_pin);

        ~Controller();

        // setChannels is primarily for ease while debugging, ideally shouldn't be used
        int setChannels(std::vector<std::string> Channels, int Type);

        std::vector<std::string> getChannels(int Type);

        int setmotor_pin(int motor_pin);

        int getmotor_pin();

        int setbrake_pin(int brake_pin);

        int getbrake_pin();

        int run();

        bool motorshutdown();

        bool brakeshutdown();
};
#endif