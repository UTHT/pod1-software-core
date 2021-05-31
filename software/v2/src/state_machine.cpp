#include <iostream>
#include <tinyfsm.hpp>
#include <data.hpp>

#include "state_machine.hpp"

// class OFF;
// class DEBUG;
class DEBUG; class LOCK; class ARM; class OFF; class DRIVE; class BRAKING; class SHUTDOWN; class ESTOP; // forward declarations

// State Declarations
class DEBUG : public SM {
    void entry() override { 
        std::cout << "Entering DEBUG" << std::endl;
        data.curr_state = DEBUG_t; };
    void react(LOCK_cmd const &) override { transit<LOCK>(); };
    void exit() override {
        std::cout << "Exiting DEBUG" << std::endl;
        data.prev_state = DEBUG_t; };
};

class ARM : public SM {
    void entry() override { 
        std::cout << "Entering ARM" << std::endl;
        data.curr_state = ARM_t; };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void react(LAUNCH_cmd const &) override { transit<DRIVE>(); };
    void exit() override {
        std::cout << "Exiting ARM" << std::endl;
        data.prev_state = ARM_t; };
};

class LOCK : public SM {
    void entry() override { 
        std::cout << "Entering LOCK" << std::endl;
        data.curr_state = LOCK_t; };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void react(ARM_cmd const &) override { transit<ARM>(); };
    void exit() override {
        std::cout << "Exiting LOCK" << std::endl;
        data.prev_state = LOCK_t; };
};

class OFF : public SM {
    void entry() override { 
        std::cout << "Entering OFF" << std::endl;
        data.curr_state = OFF_t; };
    void react(LOCK_cmd const &) override { transit<LOCK>(); };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void exit() override {
        std::cout << "Exiting OFF" << std::endl;
        data.prev_state = OFF_t; };
};

class DRIVE : public SM {
    void entry() override { 
        std::cout << "Entering DRIVE" << std::endl;
        data.curr_state = DRIVE_t; };
    void react(ESTOP_cmd const &) override { transit<ESTOP>(); };
    void react(END_OF_TRACK const &) override { transit<BRAKING>(); };
    void react(HEALTH_fail const &) override { transit<ESTOP>(); };
    void exit() override {
        std::cout << "Exiting DRIVE" << std::endl;
        data.prev_state = DRIVE_t; };
};

class BRAKING : public SM {
    void entry() override { 
        std::cout << "Entering BRAKING" << std::endl;
        data.curr_state = BRAKING_t; };
    void react(COMPLETE_STOP const &) override { transit<SHUTDOWN>(); };
    void react(HEALTH_fail const &) override { transit<ESTOP>(); };
    void exit() override {
        std::cout << "Exiting BRAKING" << std::endl;
        data.prev_state = BRAKING_t; };
};

class SHUTDOWN : public SM {
    void entry() override { 
        std::cout << "Entering SHUTDOWN" << std::endl;
        data.curr_state = SHUTDOWN_t; };
    void react(DEACTIVATED const &) override { transit<OFF>(); };
    void exit() override {
        std::cout << "Exiting SHUTDOWN" << std::endl;
        data.prev_state = SHUTDOWN_t; };
};

class ESTOP : public SM {
    void entry() override { 
        std::cout << "Entering ESTOP" << std::endl;
        data.curr_state = ESTOP_t; };
    void react(COMPLETE_STOP const &) override { transit<SHUTDOWN>(); };
    void exit() override {
        std::cout << "Exiting ESTOP" << std::endl;
        data.prev_state = ESTOP_t; };
};


FSM_INITIAL_STATE(SM, OFF)
