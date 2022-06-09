#include <iostream>
#include <tinyfsm.hpp>
#include <data.hpp>

#include "state_machine.hpp"

// class OFF;
// class DEBUG;
class DEBUG; class OFF; class ON; class DRIVE; class BRAKING; class ESTOP; // forward declarations

// State Declarations
class DEBUG : public SM {
    void entry() override { 
        std::cout << "Entering DEBUG" << std::endl;
        data.curr_state = DEBUG_t; };
    void react(ON_cmd const &) override { transit<ON>(); };
    void exit() override {
        std::cout << "Exiting DEBUG" << std::endl;
        data.prev_state = DEBUG_t; };
};

class OFF : public SM {
    void entry() override { 
        std::cout << "Entering OFF" << std::endl;
        data.curr_state = OFF_t; };
    void react(ON_cmd const &) override { transit<ON>(); };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void exit() override {
        std::cout << "Exiting OFF" << std::endl;
        data.prev_state = OFF_t; };
};

class ON : public SM {
    void entry() override { 
        std::cout << "Entering ON" << std::endl;
        data.curr_state = ON_t; };
    void react(LAUNCH_cmd const &) override { transit<DRIVE>(); };
    void react(HEALTH_fail const &) override { transit<OFF>(); };
    void exit() override {
        std::cout << "Exiting ON" << std::endl;
        data.prev_state = ON_t; };
};

class DRIVE : public SM {
    void entry() override { 
        std::cout << "Entering DRIVE" << std::endl;
        data.curr_state = DRIVE_t; };
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
    void react(COMPLETE_STOP const &) override { transit<OFF>(); };
    void react(HEALTH_fail const &) override { transit<ESTOP>(); };
    void exit() override {
        std::cout << "Exiting BRAKING" << std::endl;
        data.prev_state = BRAKING_t; };
};

class ESTOP : public SM {
    void entry() override { 
        std::cout << "Entering ESTOP" << std::endl;
        data.curr_state = ESTOP_t; };
    void react(COMPLETE_STOP const &) override { transit<OFF>(); };
    void exit() override {
        std::cout << "Exiting ESTOP" << std::endl;
        data.prev_state = ESTOP_t; };
};


FSM_INITIAL_STATE(SM, OFF)
#


// Send current state to Arduino
// Arduino sends comamnds using Canbus to inverter (converted to canbus format (8 bytes))

// In a while loop: constantly poll for broadcast messages from inverter
// Get each message, decode it, and store in hash table/data structure