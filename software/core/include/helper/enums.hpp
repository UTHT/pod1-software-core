#ifndef ARDUINOBOARDS_H
#define ARDUINOBOARDS_H

// TODO : Check if we should have separate enum files for different things

// Channel Class
enum channelStatus {NO_VALUE, OUT_OF_RANGE, LOW_FREQUENCY, HIGH_FREQUENCY, FUNCTIONING};
enum channelVariable {SENSOR_VALUE, FREQUENCY_VALUE};

// Arduino Enums
enum ArduinoBoards {FRONT_ANALOG, REAR_ANALOG, MOTOR_CONTROLLER, BRAKE_CONTROLLER};

#endif