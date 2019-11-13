#ifndef CHANNELSTATUS_H
#define CHANNELSTATUS_H
enum ChannelStatus {NO_VALUE, OUT_OF_RANGE,
                    LOW_FREQUENCY, HIGH_FREQUENCY,
                    FUNCTIONING};
#endif

// TODO (Mathieu) Why is this necessary?
#ifndef CHANNELVARIABLE_H
#define CHANNELVARIABLE_H
enum ChannelVariable {SENSOR_VALUE, FREQUENCY_VALUE};
#endif

#ifndef ARDUINOBOARDS_H
#define ARDUINOBOARDS_H
enum ArduinoBoards {FRONT_ANALOG, REAR_ANALOG,
                    MOTOR_CONTROLLER, BRAKE_CONTROLLER};
#endif
