#ifndef ENUM_H
#define ENUM_H

enum state_t { OFF, LOCK, ARM, DRIVE, BRAKING, SHUTDOWN, DEBUG, ESTOP };
enum comm_t { NO_comm, LOCK_comm, ARM_comm, DRIVE_comm, ESTOP_comm};

#endif