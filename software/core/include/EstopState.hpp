
#ifndef ESTOP_STATE_HPP
#define ESTOP_STATE_HPP

#include "State.hpp"
#include "Channel.hpp"
#include "../lcm/lcm-cpp.hpp"

class EstopState: public State{

    private:
        States name;

        //poll for launch authorization 
        Channel* launch_channel_ptr;

        //poll for potential estop request
        Channel* check_emergency_ptr;

    public:

    //default constructor
    EstopState();

    //primary constructor
    EstopState(States name);

    //check channels
    States run();

    //destructor
    ~EstopState();
};

#endif
