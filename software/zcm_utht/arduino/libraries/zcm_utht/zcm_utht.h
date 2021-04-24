// #ifdef __cplusplus
//  extern "C" {
// #endif

#ifndef ZCM_UTHT_H
#define ZCM_UTHT_H

// extern "C" {
#include "../arduino_cobs_serial_transport/arduino_cobs_serial_transport.hpp"
// }

class Zcm_utht {
    public:
        Zcm_utht(int port);
        zcm_t* get_zcm();
    private: 
        zcm_t* zcm_obj;
};

// zcm_t* create_zcm(int port);


#endif

// #ifdef __cplusplus
//  }
// #endif