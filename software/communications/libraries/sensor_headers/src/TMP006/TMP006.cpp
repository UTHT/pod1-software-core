#include "TMP006.h"

const char* arr[2] = {"deg C [Object]", "deg C [Die]"};
t_datasetup datasetup = {2, arr};

TMP006::TMP006(uint8_t addr, arduino_t arduino) : Sensor(S_TMP006, arduino, datasetup, 250){
    this->tmp006 = new Adafruit_TMP006(addr);
}

errorlevel_t TMP006::init(){
    //TODO is tmp006.wake(); required after tmp006.begin() to turn on the tmp006
    return (tmp006->begin(TMP006_CFG_4SAMPLE) ? ERR_NONE : ERR_FAIL);
}

// TODO Calibrate temperature readings
errorlevel_t TMP006::read(t_datum* data, uint8_t numdata){
    // NOTE: Convention - check that numdata given matches expected
    if(numdata != 2){ //TODO: globally declare the array size instead of using the int value
      return ERR_FAIL;
    }

    // Copy buffer
    data[0].data = tmp006->readObjTempC();
    data[1].data = tmp006->readDieTempC();

    // TODO: other error conditions?
    return ERR_NONE;
}
