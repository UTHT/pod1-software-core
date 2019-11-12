#ifndef STATEENUM_HPP
#define STATEENUM_HPP

// Declare the states using a common header 
// Common across all files by #include "state_enum.hpp" in the header

enum STATE {
	
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
