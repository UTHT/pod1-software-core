#ifndef ARDUINOBOARDS_H
#define ARDUINOBOARDS_H

// TODO : Check if we should have separate enum files for different things

// Channel Class
enum channelStatus {noValue, outOfRange, lowFrequency, highFrequency, functioning};
enum channelVariable {sensorValue, frequencyValue};

// Arduino Enums
enum ArduinoBoards {FRONT_ANALOG, REAR_ANALOG, MOTOR_CONTROLLER, BRAKE_CONTROLLER};

#endif