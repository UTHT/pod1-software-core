#include <iostream>
#include "state_machine.hpp"
#include "health_monitor.hpp"
#include "channel_handler.hpp" 
#include "data.hpp"          
#include "en.hpp"                   

struct Data data;

using fsm_handle = SM;

int main() {
    // instantiate events                                                                                                                                                                                                            
    ON_cmd on_cmd;
    LAUNCH_cmd launch_cmd;
    BRAKE_cmd brake_cmd;
    HEALTH_fail health_fail;

    HealthMonitor health_monitor;
    ChannelHandler channel_handler;

    fsm_handle::start();

    while(1){
        channel_handler.updateData();
        channel_handler.updateComm();
        channel_handler.sendBundle();

        health_monitor.healthCheck();
        if (!health_monitor.health_status) break;

        switch(data.curr_command){
            case NO_comm:   break;
            case ON_comm:  fsm_handle::dispatch(on_cmd); break;
            case DRIVE_comm:  fsm_handle::dispatch(launch_cmd); break;
            case BRAKE_comm:  fsm_handle::dispatch(brake_cmd); break;
        }       
    }
}