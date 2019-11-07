#ifndef STATEENUM_HPP
#define STATEENUM_HPP

// Declare the states using a common header 
// Common across all files by #include "state_enum.hpp" in the header

enum STATE{

	ESTOP,
	Off,
	Debug,
	CommCheck,
	SysCheck,
	Lock,
	Arm,
	Drive,
	Brake
}


#endif 
