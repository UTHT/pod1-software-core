#include <iostream>
#include <tinyfsm.hpp>

#include "state_machine.hpp"

// class OFF;
// class DEBUG;
class DEBUG; class LOCK; class ARM; class OFF; class DRIVE; class BRAKING; class SHUTDOWN; class ESTOP; // forward declarations

// State Declarations
class DEBUG : public SM {
    void entry() override { std::cout << "Entering DEBUG" << std::endl; };
    void react(LOCK_cmd const &) override { transit<LOCK>(); };
};

class ARM : public SM {
    void entry() override { std::cout << "Entering ARM" << std::endl; };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void react(LAUNCH_cmd const &) override { transit<DRIVE>(); };
};

class LOCK : public SM {
    void entry() override { std::cout << "Entering LOCK" << std::endl; };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
    void react(ARM_cmd const &) override { transit<ARM>(); };
};

class OFF : public SM {
    void entry() override { std::cout << "Entering OFF" << std::endl; };
    void react(LOCK_cmd const &) override { transit<LOCK>(); };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
};

class DRIVE : public SM {
    void entry() override { std::cout << "Entering DRIVE" << std::endl; };
    void react(ESTOP_cmd const &) override { transit<ESTOP>(); };
    void react(END_OF_TRACK const &) override { transit<BRAKING>(); };
    void react(HEALTH_fail const &) override { transit<ESTOP>(); };
};

class BRAKING : public SM {
    void entry() override { std::cout << "Entering BRAKING" << std::endl; };
    void react(COMPLETE_STOP const &) override { transit<SHUTDOWN>(); };
    void react(HEALTH_fail const &) override { transit<ESTOP>(); };
};

class SHUTDOWN : public SM {
    void entry() override { std::cout << "Entering SHUTDOWN" << std::endl; };
    void react(DEACTIVATED const &) override { transit<OFF>(); };
};

class ESTOP : public SM {
    void entry() override { std::cout << "Entering E-STOP" << std::endl; };
    void react(COMPLETE_STOP const &) override { transit<SHUTDOWN>(); };
};


FSM_INITIAL_STATE(SM, OFF)
