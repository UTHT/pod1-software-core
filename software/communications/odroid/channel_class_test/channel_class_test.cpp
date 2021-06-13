// #include <channel.hpp>
// #include <linux_cobs_serial_transport.hpp>
#include <channel.hpp>

#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    char* serial_port;

    // Get the serial port from the Arduino IDE and pass it to the program.
    if (argc == 2) {
        serial_port = argv[1];
    } else {
        serial_port = (char *) "/dev/cu.usbmodem14501";
    }

    cout << "Listening on port: " << serial_port << endl;

    // Define the sensor and subscribe to the channel
    Channel test_sensor("test_sensor", (string) serial_port, 0, 1000);

    test_sensor.subscribeToChannel();

    while (true) {
        for (auto it : channel_map) {
            Channel* channel = it.second;
            zcm_handle_nonblock(channel->getZCM());
        }
    }

    return 0;
}