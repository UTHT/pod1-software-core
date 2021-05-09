#include "../libraries/linux_cobs_serial_transport/linux_cobs_serial_transport.hpp"

// We need to centralize all zcm_types to a different folder.
// Temporary way to access the zcm types:
#include "../libraries/zcm_types/src/test_msg.h" 

#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

static void test_msg_handler(const zcm_recv_buf_t* rbuf, const char* channel, const test_msg* msg, void* user) {
    cout << "Message received on channel: " << channel << endl; 
    cout << "Message: " << msg->str << endl;
}

int main(int argc, char** argv) {
    char* serial_port;

    if (argc == 2) {
        serial_port = argv[1];
    } else {
        serial_port = "/dev/cu.usbmodem14501";
    }

    cout << "Listening on port: " << serial_port << endl;

    zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
    zcm_t* zcm = zcm_create_from_trans(linux_cobs_serial_transport);

    test_msg_subscribe(zcm, "TEST", &test_msg_handler, NULL);

    while (true) {
        zcm_handle_nonblock(zcm);
    }

    return 0;
}