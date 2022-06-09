#ifndef ENUM_H
#define ENUM_H

enum state_t { OFF_t, ON_t, DRIVE_t, BRAKING_t, DEBUG_t, ESTOP_t };
enum comm_t { NO_comm, ON_comm, DRIVE_comm, BRAKE_comm};
enum inv_state_t { PCHARGE }; // and so on..
#endif
