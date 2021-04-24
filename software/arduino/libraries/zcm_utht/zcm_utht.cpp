#include "zcm_utht.h"

Zcm_utht::Zcm_utht(int port) {
    zcm_trans_t* zcm_trans = arduino_transport_create(port);
    zcm_obj = zcm_create_from_trans(zcm_trans);    
}

zcm_t* Zcm_utht::get_zcm() {
    return zcm_obj;
}

// zcm_t* create_zcm(int port) {
//     zcm_trans_t* zcm_trans = arduino_transport_create(port);
//     return zcm_create_from_trans(zcm_trans);
// }
