#include "zcm_utht.h"

zcm_t* create_zcm(int port) {
    zcm_trans_t* zcm_trans = arduino_transport_create(port);
    return zcm_create_from_trans(zcm_trans);
}
