#ifndef TMP006_H
#define TMP006_H

#include "Sensor.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TMP006.h"

class TMP006 : public Sensor {
    public:
        TMP006(uint8_t addr, arduino_t arduino);
    private:
        Adafruit_TMP006* tmp006;
        errorlevel_t read(t_datum* data, uint8_t numdata) override;
        errorlevel_t init() override;
};

#endif
