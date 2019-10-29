#include <iostream>
#include <stdio.h>
#include <lcm/lcm-cpp.hpp>
#include "include/controller.hpp"
#include "lib/Arduino-PID-Library/PID_v1.h"
#include "Arduino.h"
#include "Stream.h"

int Controller::StateChange(int NewState) {
    
    if (NewState >= TotalStates || NewState < 0) {return -1;}

    State = NewState;

    // Motor Controller is connected
    if (motor_input_pin != -1) {

        // New Motor Values
        Motor_Kp = Motor_P[State];
        Motor_Ki = Motor_I[State];
        Motor_Kd = Motor_D[State];
        Motor_setpoint = Motor_Setpoint[State];
        Motor_PoN = Motor_POn[State];
        Motor_Dir = Motor_Direction[State];
        Motor_Mode = Motor_PID[State]; 
        Motor_upper = Motor_upperlimit[State];
        Motor_lower = Motor_lowerlimit[State];

        // Update Motor PID
        Motor.SetTunings(Motor_Kp, Motor_Ki, Motor_Kd, Motor_PoN);
        Motor.SetControllerDirection(Motor_Dir);
        Motor.SetMode(Motor_Mode);
        Motor.SetOutputLimits(Motor_lower, Motor_upper);
    }
    
    // Brake Controller is connected
    if (brake_input_pin != -1) {

        // New Brake Values
        Brake_Kp = Brake_P[State];
        Brake_Ki = Brake_I[State];
        Brake_Kd = Brake_D[State];
        Brake_setpoint = Brake_Setpoint[State];
        Brake_PoN = Brake_POn[State];
        Brake_Dir = Brake_Direction[State];
        Brake_Mode = Brake_PID[State];
        Brake_upper = Brake_upperlimit[State];
        Brake_lower = Brake_lowerlimit[State];

        // Update Brake PID
        Brake.SetTunings(Brake_Kp, Brake_Ki, Brake_Kd, Brake_PoN);
        Brake.SetControllerDirection(Brake_Dir);
        Brake.SetMode(Brake_Mode);
        Brake.SetOutputLimits(Brake_lower, MBrake_upper);
    }
    
    return 0;
}

Controller::Controller(int motor_pin, int brake_pin) :

    Motor(&Motor_input, &Motor_output, &Motor_setpoint, Motor_Kp, Motor_Ki, Motor_Kd, Motor_PoN, Motor_Dir),
    
    Brake(&Brake_input, &Brake_output, &Brake_setpoint, Brake_Kp, Brake_Ki, Brake_Kd, Brake_PoN, Brake_Dir)

{

    if (motor_pin > 0) { motor_input_pin = motor_pin;}
    if (brake_pin > 0) { brake_input_pin = brake_pin;}

    // Arduino Library import Needed

    // Motor Controller is connected
    if (motor_input_pin != -1) {
        Motor_input = analogRead(motor_input_pin);
    }

    // Brake Controller is connected
    if (brake_input_pin != -1) {
        Brake_input = analogRead(brake_input_pin);
    }
    
    Motor.SetOutputLimits(Motor_lower, Motor_upper);
    Brake.SetOutputLimits(Brake_lower, Brake_upper);
    time = millis();
}

Controller::~Controller() {

    Essential_Channels.clear();
    Motor_Channels.clear();
    Brake_Channels.clear();
}

int Controller::setChannels(std::vector<std::string> Channels, int Type) {
    
    switch(Type) {
        case 0: Essential_Channels = Channels;
                break;
        case 1: Motor_Channels = Channels;
                break;
        case 2: Brake_Channels = Channels;
                break;

        default: return -1;
                break;
    }

    return 0;
}

std::vector<std::string> Controller::getChannels(int Type) {

    switch(Type) {
        case 0: return Essential_Channels;
                
        case 1: return Motor_Channels;
                
        case 2: return Brake_Channels;
            
        default: return (std::vector<std::string> {});
    }
}

int Controller::setmotor_pin(int motor_pin) {

    if (motor_pin > 0) { motor_input_pin = motor_pin;}
    else {return -1;}
    return 0;
}

int Controller::getmotor_pin() {

    return motor_input_pin;
}

int Controller::setbrake_pin(int brake_pin) {

    if (brake_pin > 0) { brake_input_pin = brake_pin;}
    else {return -1;}
    return 0;
}

int Controller::getbrake_pin() {
    
    return brake_input_pin;
}

int Controller::run() { // TODO:Add error checking to return error code on problem

    // Comms stuff
    // Data process stuff

    // if new state: call state StateChange

    // Compute sample time
    Sampletime = time - millis();
    time = millis();

    Motor.SetSampleTime(Sampletime);
    Motor.Compute();

    Brake.SetSampleTime(Sampletime);
    Brake.Compute();
}

bool Controller::motorshutdown() {

    Motor.SetMode(MANUAL);
    analogWrite(motor_input_pin, 255);
    return true;
}

bool Controller::brakeshutdown() {

    Brake.SetMode(MANUAL);
    analogWrite(brake_input_pin, 0); // 0 Power makes Brakes ON in case of power loss, REVERSE Control
    return true;
}