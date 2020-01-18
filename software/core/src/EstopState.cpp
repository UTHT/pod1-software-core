
#include "EstopState.hpp"

//default constructor
EstopState::EstopState():State(){}


//primary constructor
EstopState::EstopState(States name):State(name){
    this->name = name;
    this->launch_channel_ptr = new Channel("data-launch-ready");
    this->check_emergency_ptr = new Channel("command-estop");
}


//function to request data from States 
States EstopState::run(){

    //TODO: We currently assume that the 'get()' function
    //      returns a bool. We will most likely need to update
    //      this syntax to reflect changes to the channel class
    //      in the future. (e.g. template parameters)

    //first check for emergency break triggers
    if (check_emergency_ptr->get()){
        return ESTOP;
    }

    //check for run trigger
    if (launch_channel_ptr->get()){
        return DRIVE;
    }
    
    //default case is to stay in Arm State
    return ARM;
}


//destructor
EstopState::~EstopState(){

    //delete channel objects if they exist

    if (this->launch_channel_ptr != NULL){
        delete this->launch_channel_ptr;
        this->launch_channel_ptr = NULL;
    }

    if (this->check_emergency_ptr != NULL){
        delete this->check_emergency_ptr;
        this->check_emergency_ptr = NULL;
    }
}
