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
    if (data.temp_front.values[0] > 72 || data.temp_front.values[0] < 0) health_status = false;
    if (data.temp_back.values[0] > 44 || data.temp_back.values[0] < 0) health_status = false;
    if (data.accel.values[0] > 61 || data.accel.values[0] < 0) health_status = false;
    if (data.velocity.values[0] > 69 || data.velocity.values[0] < 0) health_status = false;
    if (data.velocity_inv.values[0] > 29 || data.velocity_inv.values[0] < 0) health_status = false;
    if (data.DC_curr.values[0] > 22 || data.DC_curr.values[0] < 0) health_status = false;
    if (data.pressure_1000.values[0] > 34 || data.pressure_1000.values[0] < 0) health_status = false;
    if (data.pressure_200_1.values[0] > 9 || data.pressure_200_1.values[0] < 0) health_status = false;
    if (data.pressure_200_2.values[0] > 17 || data.pressure_200_2.values[0] < 0) health_status = false;
    if (data.gap_height.values[0] > 46 || data.gap_height.values[0] < 0) health_status = false;
    if (data.position.values[0] > 65 || data.position.values[0] < 0) health_status = false;
    if (data.vibration.values[0] > 14 || data.vibration.values[0] < 0) health_status = false;
}