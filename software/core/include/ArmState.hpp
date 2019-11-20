
#ifndef ARM_STATE_HPP
#define ARM_STATE_HPP

#include "State.hpp"
#include "Channel.hpp"

class ArmState: public State{

    private:
        States name;

        //poll for launch authorization 
        Channel* launch_channel_ptr;

        //poll for potential estop request
        Channel* check_emergency_ptr;

    public:

    //default constructor
    ArmState();

    //primary constructor
    ArmState(States name);

    //check channels
    States run();

    //destructor
    ~ArmState();
};

#endif
