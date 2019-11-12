#ifndef ARDUINOBOARDS_H
#define ARDUINOBOARDS_H

enum channelStatus {noValue, outOfRange, lowFrequency, highFrequency, functioning};
enum channelVariable {sensorValue, frequencyValue};

enum ArduinoBoards {FRONT_ANALOG, REAR_ANALOG, MOTOR_CONTROLLER, BRAKE_CONTROLLER};

#endif