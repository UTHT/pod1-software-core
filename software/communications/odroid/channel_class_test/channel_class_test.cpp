// #include <channel.hpp>
#include <linux_cobs_serial_transport.hpp>
#include <channel.hpp>

#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

unordered_map<string, Channel*> channel_map;

int main(int argc, char** argv) {
    char* serial_port;

    // Get the serial port from the Arduino IDE and pass it to the program.
    if (argc == 2) {
        serial_port = argv[1];
    } else {
        serial_port = (char *) "/dev/cu.usbmodem14501";
    }

    cout << "Listening on port: " << serial_port << endl;

    // Define the transport layer to the Arduino
    zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
    zcm_t* zcm = zcm_create_from_trans(linux_cobs_serial_transport);

    // Define the sensor and subscribe to the channel
    Channel test_sensor("test_sensor", 0, 1000);
    channel_map["test_sensor"] = &test_sensor;

    test_sensor.subscribeToChannel(zcm);

    while (true) {
        zcm_handle_nonblock(zcm);
    }

    return 0;
}