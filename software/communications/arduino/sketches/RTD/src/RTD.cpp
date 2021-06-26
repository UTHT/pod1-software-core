#include "RTD.h"

const char* arr[2] = {"deg F (Raw)", "deg F"};
t_datasetup datasetup = {2, arr};

RTD::RTD(uint8_t pin, arduino_t arduino) : Sensor(S_PROSENSERTD, arduino, datasetup, 500){
    this->pin = pin;
}

errorlevel_t RTD::init(){
    pinMode(pin, INPUT);
    return ERR_NONE;
}

double prosense_rtd_map(const int x, const double in_min, const double in_max, const double out_min, const double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// TODO Calibrate temperature readings
errorlevel_t RTD::read(t_datum* data, uint8_t numdata){
    // NOTE: Convention - check that numdata given matches expected
    if(numdata != 2){ //TODO: globally declare the array size instead of using the int value
      return ERR_FAIL;
    }
    int val = analogRead(pin);
    data[0].data = (float)val;
    data[1].data = (float)prosense_rtd_map(val, 180, 901, -40, 300);
    // TODO: other error conditions?
    return ERR_NONE;
}