#ifndef ENUM_H
#define ENUM_H

enum state_t { OFF_t, LOCK_t, ARM_t, DRIVE_t, BRAKING_t, SHUTDOWN_t, DEBUG_t, ESTOP_t };
enum comm_t { NO_comm, LOCK_comm, ARM_comm, DRIVE_comm, ESTOP_comm};

#endif