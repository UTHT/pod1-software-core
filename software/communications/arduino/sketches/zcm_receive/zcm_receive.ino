#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <channel_array_msg.h>

zcm_t* zcm_arduino;
int counter;

void setup() {
  // put your setup code here, to run once:
  zcm_arduino = create_zcm(0);
  counter = 0;
}

static void channel_array_handler(const zcm_recv_buf_t *rbuf, const char *channel, const channel_array *msg, void *user) {
    // Arduino should do something here
}

void loop() {
    zcm_handle_nonblock(zcm_arduino);

    channel_array_subscribe(zcm_arduino, "test", &channel_array_handler, NULL);
}