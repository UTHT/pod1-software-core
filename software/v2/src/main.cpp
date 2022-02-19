#include <iostream>
#include "state_machine.hpp"
#include "health_monitor.hpp"
#include "channel_handler.hpp" 
#include "data.hpp"      
#include "inv_data.hpp"      
#include "en.hpp"                   

struct Data data;
struct inv_data inv_data;

using fsm_handle = SM;

int main() {
    // instantiate events                                                                                                                                                                                                            
    LOCK_cmd lock_cmd;
    ARM_cmd arm_cmd;
    LAUNCH_cmd launch_cmd;
    ESTOP_cmd estop_cmd;
    HEALTH_fail health_fail;

    HealthMonitor health_monitor;
    ChannelHandler channel_handler;

    fsm_handle::start();

    while(1){
        channel_handler.updateData();
        channel_handler.updateComm();

        health_monitor.healthCheck();
        if (!health_monitor.health_status) break;

        switch(data.curr_command){
            case NO_comm:   break;
            case LOCK_comm:  fsm_handle::dispatch(lock_cmd); break;
            case ARM_comm:  fsm_handle::dispatch(arm_cmd); break;
            case DRIVE_comm:  fsm_handle::dispatch(launch_cmd); break;
            case ESTOP_comm:  fsm_handle::dispatch(estop_cmd); break;
        }       
    }
}