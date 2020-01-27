
#ifndef ARM_STATE_HPP
#define ARM_STATE_HPP

#include "State.hpp"
#include "Channel.hpp"

class ArmState: public State{
    private:
        //poll for launch authorization
        Channel* launch_channel_ptr;
        //poll for potential estop request
        Channel* check_emergency_ptr;

    public:
    //primary constructor
    ArmState(States name);
    //destructor
    ~ArmState();
    //check channels
    States run();
};

#endif
