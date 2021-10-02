#include <stdlib.h>
#include "Arduino.h"
#include "Sensor.h"

/**
 * Constructor. 
 * @param sensor - sensors_t - Which sensor is this?
 * @param arduino - arduino_t - Which Arduino are we attached to?
 * @param setup - t_datasetup - How many datasets are there? What are their units?
 * @param delta - uint16_t - The minimum time (in ms) between sensor read attempts.
 **/
Sensor::Sensor(sensors_t sensor, arduino_t arduino, t_datasetup setup, uint16_t delta){
    // Set up cache
    this->sensor = sensor;
    this->arduino = arduino;
    state.error = ERR_NONE;
    state.debug = DS_DISABLED;
    state.timestamp = millis();

    // Allocate data locations
    state.data = (t_datum*)malloc(sizeof(t_datum)*(setup.numdata));
    state.numdata = setup.numdata;
    for(int i = 0; i < setup.numdata; i++){
        // Since setup.units[i] is a const char*, we can just reassign our pointer
        state.data[i].units = setup.units[i];
    }

    this->delta = delta;
    lastread = millis();    //Buffer - Resets the last read time to the current time
}

SensorState* Sensor::begin(){
    state.error = init();
    if(state.error > ERR_NONE){
        state.debug = DS_DISABLED;
    } else {
        state.debug = DS_INIT;
    }
    return &state;
}

/**
 * Wrapper for hardware-level read function. Updates the state.
 * Checks that enough time has passed between reads.
 **/
SensorState* Sensor::update(){
    // Check preconditions
    if(state.error < ERR_FAIL && state.debug >= DS_INIT){
        // Check timing
        if(millis()-lastread > delta){
            // Create buffer
            t_datum* buffer = (t_datum*)malloc(sizeof(t_datum)*state.numdata);
            for(int i = 0; i < state.numdata; i++){
                buffer[i].units = state.data[i].units;
            }

            state.error = read(buffer, state.numdata);
            lastread = millis();    //Reset the last read attempt time to now

            switch(state.error){
                case ERR_NONE:  //Success!
                    state.debug = DS_NEWREAD;
                    state.timestamp = lastread;
                    free(state.data);
                    state.data = buffer;
                    break;
                case ERR_WARN:  //Read didn't go as planned, non-fatal
                    // DO NOT UPDATE STATE VALUES
                    break;
                case ERR_FAIL:  //Read failed catastrophically
                    state.debug = DS_DISABLED;
                    break;
            }
        } else {
            state.debug = DS_WAITING;
        }
    }
    return &state;
}