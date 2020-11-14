#include "sm.h"

#include <iostream>
#include <tinyfsm.hpp>

// class OFF;
// class DEBUG;
class LOCK; // forward declaration

// State Declarations
class DEBUG : public SM {
    void entry() override { std::cout << "Entering DEBUG" << std::endl; };
    void react(LOCK_cmd const &) override { transit<LOCK>(); };
};

class ARM : public SM {
    void entry() override { std::cout << "Entering ARM" << std::endl; };
    void react(HEALTH_fail const &) override { transit<DEBUG>(); };
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

FSM_INITIAL_STATE(SM, OFF)

using fsm_handle = SM;

int main() {
    // instantiate events
    LOCK_cmd lock_cmd;
    ARM_cmd arm_cmd;
    HEALTH_fail health_fail;

    fsm_handle::start();

    while (1) {
        char c;
        std::cin >> c;
        switch (c) {
            case 'l':
                std::cout << "Sending LOCK cmd" << std::endl;
                fsm_handle::dispatch(lock_cmd);
                break;
            case 'h':
                std::cout << "Systems Health Check Failed" << std::endl;
                fsm_handle::dispatch(health_fail);
                break;
            case 'a':
                std::cout << "Sending ARM cmd" << std::endl;
                fsm_handle::dispatch(arm_cmd);
                break;
            case 'q':
                return 0;
            default:
                std::cout << "Invalid input" << std::endl;
        };
    }
}