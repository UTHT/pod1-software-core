// Headers for each sensor type
#include "src/VFS500.h" 
//...

#include "src/Sensor.h"
#define NUMSENSORS 1 //Or however many
#define BAUDRATE 115200
#define THISARDUINO ARDUINO_ONE

// Objects for each sensor
VFS500 vfs500(A0, THISARDUINO); 
//...

Sensor* sensors[NUMSENSORS] = {
    // Entry for each sensor object
    &vfs500, 
    //...
};

// !#!#!#!--- EVERYTHING AFTER HERE DOES NOT NEED TO BE CHANGED FOR SENSOR IMPLEMENTATION ---!#!#!#!

void setup(){
    Serial.begin(BAUDRATE);

    bool success = true;
    for(int i = 0; i < NUMSENSORS; i++){
        SensorState* state = sensors[i]->begin();
        // Print/send sensor post-setup state data here. For example:
        bool _success = (state->error == ERR_NONE);
        if(_success){
            Serial.print("Sensor ");
            Serial.print(sensors[i]->sensor);
            Serial.println(" initialized.");
        } else {
            Serial.print("Sensor ");
            Serial.print(sensors[i]->sensor);
            Serial.println(" failed to initialize!");
        }
        success &= _success;
    }
    if(!success){
        Serial.println("POST failed on one or more sensors, freezing...");
        while(1){delay(1000);}
    }
}

void loop(){
    for(int i = 0; i < NUMSENSORS; i++){
        SensorState* state = sensors[i]->update();
        // Print/send sensor post-setup state data here. For example:
        bool _success = (state->error == ERR_NONE);
        bool _new = (state->debug == DS_SUCCESS);
        if(_success && _new) {
            Serial.print("Sensor ");
            Serial.print(sensors[i]->sensor);
            Serial.print(" read success: ");
            for(int x = 0; x < state->numdata; x++){
                Serial.print(state->data[x].data);
                Serial.print(' ');
                Serial.print(state->data[x].units);
                if(x < state->numdata-1){Serial.print(", ");}else{Serial.println();}
            }
        } else if (!_success) {
            Serial.print("Sensor ");
            Serial.print(sensors[i]->sensor);
            Serial.println(" failed to update!");
            // TODO: Recover failed sensor?
        }
    }
}
