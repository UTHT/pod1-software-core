#if ARDUINO >= 100
    #include "Arduino.h"
#else
   // #include "WProgram.h"
#endif

#include "helper/enums.hpp"
#include "helper/IOPin.hpp"
#include "PIDController.hpp"


PIDController::PIDController(const struct IOPin io_pin,
                             const struct PIDParameters pid_parameters) :

    Controller(&Input, &Output, &Setpoint, 
                pid_parameters.Kp, pid_parameters.Ki, pid_parameters.Kd, 
                pid_parameters.PoN, pid_parameters.Direction)

{
    this->setPin(io_pin);
    this->setParameters(pid_parameters);
}

PIDController::PIDController(const PIDController & src) = default;

PIDController::~PIDController() = default;

int PIDController::setPin(const struct IOPin io_pin) {

    if (io_pin.pin_number < 0) {
        return -1;
    }
    this->io_pin = io_pin;
    return 0;
}

struct IOPin PIDController::getPin() {

    return this->io_pin;
}

void PIDController::setParameters(const struct PIDParameters pid_parameters) {

    this->pid_parameters = pid_parameters;
    this->Setpoint = pid_parameters.Setpoint; // Updating pointer reference to Setpoint

    // Update Controller PID
    Controller.SetTunings(pid_parameters.Kp, pid_parameters.Ki, pid_parameters.Kp, pid_parameters.PoN);
    Controller.SetControllerDirection(pid_parameters.Direction);
    Controller.SetMode(pid_parameters.Mode);
    Controller.SetOutputLimits(pid_parameters.lowerLimit, pid_parameters.upperLimit);
}

struct PIDParameters getParameters() {

    return this->pid_parameters;
}

bool PIDController::run(const double sensor_reading) { // TODO: Add error checking to return error code on problem

    bool status;
    this->Input = sensor_reading; // Updating pointer reference to Sensor Reading
    status = Controller.Compute();
    analogWrite(io_pin.pin_number, Output);
    return status;
}

void PIDController::shutdown() {
    Controller.SetMode(MANUAL);
}