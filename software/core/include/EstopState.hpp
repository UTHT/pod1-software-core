
#ifndef ESTOP_STATE_HPP
#define ESTOP_STATE_HPP

#include <string>
#include "State.hpp"
#include "Channel.hpp"
//#include <lcm/lcm-cpp.hpp>

//passes pointer of data structure to channel handler for it
//to update
void lcm_channel_handler(estop_channel_flag* flag_struct);

//data structure that channel will update
struct estop_channel_flag
{
    bool estop_raised;
    std::string raised_state_name;
};

//estop state
class EstopState: public State{

    private:
        States name;
        //poll for launch authorization 
        estop_channel_flag estop_info;

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
