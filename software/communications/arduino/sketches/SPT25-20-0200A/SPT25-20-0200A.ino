// Headers for each sensor type
#include "src/SPT25-20-0200A.h" 
//...
#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <channel_msg.h>

#include "src/Sensor.h"
#define NUMSENSORS 1 //Or however many
#define BAUDRATE 115200
#define THISARDUINO ARDUINO_ONE

// Objects for each sensor
SPT25_20_0200A spt25_20_0200a(3, THISARDUINO); 
//...

Sensor* sensors[NUMSENSORS] = {
    // Entry for each sensor object
    &spt25_20_0200a, 
    //...
};
zcm_t* zcm_arduino;

// !#!#!#!--- EVERYTHING AFTER HERE DOES NOT NEED TO BE CHANGED FOR SENSOR IMPLEMENTATION ---!#!#!#!

void setup(){
    Serial.begin(BAUDRATE);

    bool success = true;
    for(int i = 0; i < NUMSENSORS; i++){
        SensorState* state = sensors[i]->begin();
        // Print/send sensor post-setup state data here. For example:
        bool _success = (state->error == ERR_NONE);
        if(_success){
            // Serial.print("Sensor ");
            // Serial.print(sensors[i]->sensor);
            // Serial.println(" initialized.");
        } else {
            // Serial.print("Sensor ");
            // Serial.print(sensors[i]->sensor);
            // Serial.println(" failed to initialize!");
        }
        success &= _success;
    }
    if(!success){
        // Serial.println("POST failed on one or more sensors, freezing...");
        while(1){delay(1000);}
    }
      zcm_arduino = create_zcm(0);
}

int publishTestToChannel(zcm_t* zcm, double value, String channel) {  
  channel_msg message;
  message.arduino_id = ARDUINO_ONE;
  message.sensor_id = S_SPTD25_20_0200A;
  message.sensor_value = value;

  return channel_msg_publish(zcm, channel.c_str(), &message);
}

void loop(){
    zcm_handle_nonblock(zcm_arduino);
    for(int i = 0; i < NUMSENSORS; i++){
        SensorState* state = sensors[i]->update();
        // Print/send sensor post-setup state data here. For example:
        bool _success = (state->error == ERR_NONE);
        bool _new = (state->debug == DS_NEWREAD);
        if(_success){
            if(_new){
                // Serial.print("Sensor ");
                // Serial.print(sensors[i]->sensor);
                // Serial.print(" read success: ");
                for(int x = 0; x < state->numdata; x++){
                    // Serial.print(state->data[x].data);
                    // Serial.print(' ');
                    // Serial.print(state->data[x].units);
                    // if(x < state->numdata-1){Serial.print(", ");}else{Serial.println();}
                    publishTestToChannel(zcm_arduino, state->data[x].data, "test_sensor");
                }
            }
        } else {
            // Serial.print("Sensor ");
            // Serial.print(sensors[i]->sensor);
            // Serial.println(" failed to update!");
            // TODO: Recover failed sensor?
        }
    }
}
