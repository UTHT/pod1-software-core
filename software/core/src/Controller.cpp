// #if ARDUINO >= 100
//     #include "Arduino.h"
// #else
//    // #include "WProgram.h"
// #endif

#include <stdio.h>
#include <vector>

#include "../include/State.hpp"
#include "../include/Controller.hpp"
#include "../include/helper/enums.hpp"
#include "../include/helper/IOPin.hpp"

Controller::Controller(
    const struct IOPin io_pin,
    const States current_state,
    const std::vector<Channel> channels)
{

    this->current_state = current_state;
    this->io_pin = io_pin;
    this->channels = channels;

    // Communications Object Declarations, etc
}

void Controller::state_change(const States change_to) {

  this->current_state = change_to;
}

// run() & shutdown() removed as Controller is the base class
// they will be defined in the derived motor & brake classes
// specific to their functionality
Controller:BrakeController::BrakeController(unint8_t LEDpin, unint8_t motorPin, unint8_t value){
    // initialize pins for motor and red LED
    (this -> Io_pin).LEDpin = LEDpin;
    (this -> Io_pin).motorPin = motorPin; 
    this -> value = value;
     //Use an LED to show we are in the brake state
    pinMode(Io_pin.LEDpin, OUTPUT);  // What's OUTPUT as an unint8_t??
    pinMode(Io_pin.motorPin, OUTPUT); 
}


bool Controller:BrakeController::shutdown(unint8_t value){
// check that we are in the brake state before intiating any brake commands. If we aren't 
// in the brake state, then make the change ourselves
 if (current_state != BRAKE){
     state_change(BRAKE);
     digitalWrite(IO_pin.LEDpin, 1);
     //value should be like 0
     digitalWrite(IO_pin.motorPin, value);
     return true; // I could also not proceed with braking and just return false instead
     }
 else{
     digitalWrite(IO_pin.LEDpin, 1);
     //value should be like 0
     digitalWrite(IO_pin.motorPin, value); 
     return true;
 }
}
      