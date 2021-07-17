#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

int publishTestToChannel(zcm_t* zcm, double values[], String channel, String units, int numData) {  
  channel_array message;
  message.arduino_id = 1000;
  message.sensor_id = 1001;
  message.data = values;
  message.units = (char *) units.c_str();
  message.sz = numData;

  return channel_array_publish(zcm, channel.c_str(), &message);
}

int main(int argc, char** argv) {
    char* serial_port;

    // Get the serial port from the Arduino IDE and pass it to the program.
    if (argc == 2) {
        serial_port = argv[1];
    } else {
        serial_port = (char *) "/dev/cu.usbmodem14501";
    }

    cout << "Listening on port: " << serial_port << endl;

    zcm_trans_t* linux_cobs_serial_transport = linux_cobs_serial_transport_create(serial_port);
    zcm_t* zcm = zcm_create_from_trans(linux_cobs_serial_transport);
    double tempArray [3]= {10,20,30};
    while (true) {
        zcm_handle_nonblock(zcm);
        publishTestToChannel(zcm,tempArray,"test","Ohms",sizeof(tempArray));
    }
}