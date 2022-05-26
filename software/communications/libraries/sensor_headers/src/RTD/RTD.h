#ifndef RTD_H
#define RTD_H

#include "Sensor.h"

class RTD : public Sensor {
    public:
        RTD(uint8_t pin, arduino_t arduino);
    private:
        errorlevel_t read(t_datum* data, uint8_t numdata) override;
        errorlevel_t init() override;
        /**
         * Analog input pin.
         * */
        uint8_t pin;
};

#endif