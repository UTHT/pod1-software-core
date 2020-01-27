
#include "ArmState.hpp"

//primary constructor
ArmState::ArmState(States name):State(name){
    this->launch_channel_ptr = new Channel("data-launch-ready");
    this->check_emergency_ptr = new Channel("command-estop");
}


//function to request data from States
States ArmState::run(){
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
ArmState::~ArmState(){

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
