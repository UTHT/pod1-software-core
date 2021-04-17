#ifndef zcm_utht
#define zcm_utht

#include "zcm_transport/arduino_cobs_serial_transport.hpp"

class Zcm_utht {
    public:
        Zcm_utht(int port);
        zcm_t* get_zcm();
    private: 
        zcm_t* zcm_obj;
};

// zcm_t* create_zcm(int port);


#endif