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

#ifndef STATEENUM_HPP
#define STATEENUM_HPP
enum States {
	ESTOP,
	OFF,
	DEBUG,
	COMMS_CHECK,
	SYS_CHECK,
	LOCK,
	ARM,
	DRIVE,
	BRAKE
};


#endif
