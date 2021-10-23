// Headers for each sensor type
#include "src/SPT25-20-0200A.h" 
#include "src/TMP006.h" 
//...
#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <channel_array_msg.h>

#include "Sensor.h"
#define NUMSENSORS 2 //Or however many
#define BAUDRATE 115200
#define THISARDUINO ARDUINO_ONE

TMP006 tmp006(TMP006_I2CADDR, THISARDUINO); 
SPT25_20_0200A spt25_20_0200a(3, THISARDUINO); //...

Sensor* sensors[NUMSENSORS] = {
    // Entry for each sensor object
    &spt25_20_0200a, 
    &tmp006, 
    //...
};

String sensor_names[NUMSENSORS] = {"SPT25-20-0200A", "TMP006"};

zcm_t* zcm_arduino;

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

int publishTestToChannel(zcm_t* zcm, double values[], String sensorName, String units, int numData) {    
  channel_array message;
  message.arduino_id = ARDUINO_ONE;
  message.sensor = (char *) sensorName.c_str();
  message.data = values;
  message.units = (char *) units.c_str();
  message.sz = numData;

  return channel_array_publish(zcm, sensorName.c_str(), &message);
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
                
                publishTestToChannel(zcm_arduino, values, sensor_names[i], units, state->numdata);
            }
        } else {
            // Serial.println(" failed to update!");
        }
    }
}
