#ifndef ARDUINO_SIMUL_ZCM_HELPERS
#define ARDUINO_SIMUL_ZCM_HELPERS

#ifdef COMPILE_FOR_ARDUINO
#include "arduino_cobs_serial_transport.hpp"
#endif

#ifdef COMPILE_FOR_SIMUL
#include "zcm/zcm.h"
#endif

#ifdef COMPILE_FOR_ARDUINO
  #define ARDUINO_SIMUL_CREATE_ZCM(ZCM_NAME, PORT) \
        ZCM_NAME = zcm_create_trans(arduino_transport_create(PORT));

  #define ARDUINO_SIMUL_ZCM_START(ZCM_NAME)

  #define ARDUINO_SIMUL_ZCM_HANDLE(ZCM_NAME) \
        zcm_handle_nonblock(ZCM_NAME);

#endif

#endif