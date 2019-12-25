#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "PID_v1.h"

class PIDController {
    private:
        
        struct IOPin io_pin;
        STATES current_state;

        double Input = 0;
        double Output = 0;
        std::vector<double> Kp;
        std::vector<double> Ki;
        std::vector<double> Kd;
        std::vector<double> Setpoint;
        std::vector<int> PoN;
        std::vector<int> Direction;
        std::vector<int> Mode;
        std::vector<double> upperLimit;
        std::vector<double> lowerLimit;


        // PID Library requires a pointer reference to the setpoint
        double* goal;

        // PID Controller
        PID Controller;

    public:

        PIDController(const struct IOPin io_pin,
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
                      const std::vector<double> lowerLimit);

        PIDController(const PIDController & src);

        ~PIDController();

        int setpin(const struct IOPin io_pin);

        struct IOPin getpin();

        // Update State Value upon state changes
        int state_change(const STATES change_to);

        bool update();
};
#endif