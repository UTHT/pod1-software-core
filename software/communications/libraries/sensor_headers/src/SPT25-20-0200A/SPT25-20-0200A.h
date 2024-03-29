#ifndef SPT25_20_0200A_H
#define SPT25_20_0200A_H

#include "Sensor.h"

class SPT25_20_0200A : public Sensor {
    public:
        SPT25_20_0200A(uint8_t pin, arduino_t arduino);
    private:
        errorlevel_t read(t_datum* data, uint8_t numdata) override;
        errorlevel_t init() override;
        /**
         * Analog input pin.
         * */
        uint8_t pin;
};

#endif
