#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "helper/PIDParameters.hpp"
#include "PID_v1.h"

class PIDController {
    private:

        struct IOPin io_pin;
        struct PIDParameters pid_parameters;

        double Input = 0.0;          // input of sensor reading
        double Output = 0.0;         // output of pwm spectrum
        double Setpoint = 0.0;       // desired sensor reading

        // PID Controller
        // TODO naming convention
        PID Controller;

    public:

        PIDController(const struct IOPin io_pin,
                      const struct PIDParameters pid_parameters); // TODO naming convention

        PIDController(const PIDController & src);

        ~PIDController();

        int setPin(const struct IOPin io_pin);

        struct IOPin getPin();

        // Update PID Parameters
        void setParameters(const struct PIDParameters pid_parameters);

        struct PIDParameters getParameters();

        bool run(const double sensor_reading);

        void shutdown();
};
#endif
