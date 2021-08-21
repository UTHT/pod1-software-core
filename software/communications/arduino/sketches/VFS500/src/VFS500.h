#ifndef VFS500_H
#define VFS500_H

#include "Sensor.h"

class VFS500 : public Sensor {
    public:
        VFS500(uint8_t pin, arduino_t arduino);
    private:
        errorlevel_t read(t_datum* data, uint8_t numdata) override;
        errorlevel_t init() override;
        /**
         * Analog input pin.
         * */
        uint8_t pin;
};

#endif