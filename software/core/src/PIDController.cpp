#include "..\include\PIDController.hpp"


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

void PIDController::setPin(const struct IOPin _io_pin) {

    assert(_io_pin.pin_number > 0);
    io_pin = _io_pin;
}

struct IOPin PIDController::getPin() {

    return this->io_pin;
}

void PIDController::setParameters(const struct PIDParameters _pid_parameters) {

    pid_parameters = _pid_parameters;
    Setpoint = pid_parameters.Setpoint; // Updating pointer reference to Setpoint

    // Update Controller PID
    Controller.SetTunings(pid_parameters.Kp, pid_parameters.Ki, pid_parameters.Kp, pid_parameters.PoN);
    Controller.SetControllerDirection(pid_parameters.Direction);
    Controller.SetMode(pid_parameters.Mode);
    Controller.SetOutputLimits(pid_parameters.lowerLimit, pid_parameters.upperLimit);
}

struct PIDParameters PIDController::getParameters() {

    return this->pid_parameters;
}

struct runResult PIDController::run(const double sensor_reading) { // TODO: Add error checking to return error code on problem

    bool status;
    Input = sensor_reading; // Updating pointer reference to Sensor Reading
    status = Controller.Compute();
    analogWrite(io_pin.pin_number, Output);
    
    runResult return_value(Output, status);
    return return_value;
}

void PIDController::shutdown() {
    Controller.SetMode(MANUAL);
}
