// Headers for each sensor type
#include "src/TMP006.h" 
//...
#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <channel_array_msg.h>

#include "src/Sensor.h"
#define NUMSENSORS 1 //Or however many
#define BAUDRATE 115200
#define THISARDUINO ARDUINO_ONE

// Objects for each sensor
TMP006 tmp006(TMP006_I2CADDR, THISARDUINO); 
//...

Sensor* sensors[NUMSENSORS] = {
    // Entry for each sensor object
    &tmp006, 
    
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
        Serial.println("POST failed on one or more sensors, freezing...");
        while(1){delay(1000);}
    }
    
    zcm_arduino = create_zcm(0);
}

int publishMessageToChannel(zcm_t* zcm, double values[], String channel, String units, int numData) {  
  channel_array message;
  message.arduino_id = THISARDUINO;
  message.sensor_id = TMP006_I2CADDR;
  message.data = values;
  message.units = (char *) units.c_str();
  message.sz = numData;

  return channel_array_publish(zcm, channel.c_str(), &message);
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
                double values[state->numdata];
                String units = "";

                for(int x = 0; x < state->numdata; x++){
                    values[x] = state->data[x].data; 

                    units += state->data[x].units;
                    units += ", ";
                }

                publishMessageToChannel(zcm_arduino, values, "test_sensor", units, state->numdata);
            }
        } else {
            Serial.print("Sensor ");
            Serial.print(sensors[i]->sensor);
            Serial.println(" failed to update!");
            // TODO: Recover failed sensor?
        }
    }
}
