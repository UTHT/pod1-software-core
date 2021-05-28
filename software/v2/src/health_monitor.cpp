// recieve data from zcm
//temperature sensor
//Read the data
//Check if in homeostatic range
//If not, trigger event, collect data of failure
//Return state
#include "health_monitor.hpp"
#include "state_machine.hpp"
#include "data.hpp"

void HealthMonitor::healthCheck(){
    if (data.temp_center.values[0] > 50 || data.temp_center.values[0] < 0) health_status = false;
}