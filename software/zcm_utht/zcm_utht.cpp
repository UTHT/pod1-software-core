#include "zcm_utht.h"

zcm_t* create_zcm(int port) {
    return zcm_create_trans(arduino_transport_create(port));
}
