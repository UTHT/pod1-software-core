#include "SPT25-20-0200A.h"

const char* arr_SPT[2] = {"kPa (Raw)", "kPa"};
t_datasetup datasetup_SPT = {2, arr_SPT};

SPT25_20_0200A::SPT25_20_0200A(uint8_t pin, arduino_t arduino) : Sensor(S_SPTD25_20_0200A, arduino, datasetup_SPT, 250){
    this->pin = pin;
}

errorlevel_t SPT25_20_0200A::init(){
    pinMode(pin, INPUT);
    return ERR_NONE;
}

double spt25_20_200a_map(const int x, const double in_min, const double in_max, const double out_min, const double out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

// TODO Calibrate from 0 psi to 200 psi
// Currently sensorValue at 0 psi is 176 - 177
errorlevel_t SPT25_20_0200A::read(t_datum* data, uint8_t numdata){
    // NOTE: Convention - check that numdata given matches expected
    if(numdata != 2){//TODO: globally declare the array size instead of using the int value
      return ERR_FAIL;
    }
    int val = analogRead(pin);
    data[0].data = (float)val;
    data[1].data = (float)spt25_20_200a_map(val, 176.0, 1023.0, 0, 200.0);
    // TODO: other error conditions?
    return ERR_NONE;
}
