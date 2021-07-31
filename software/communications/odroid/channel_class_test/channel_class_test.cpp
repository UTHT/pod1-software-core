// #include <channel.hpp>
// #include <linux_cobs_serial_transport.hpp>
#include <channel.hpp>

#include <stdint.h>
#include <string>
#include <iostream>

using namespace std;

void SPTcallbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_array* msg, void* user) {
    // Get the pointer to the channel
    // string channelString(channel);
    // Channel* channelObj = channel_map[channelString];
    cout << "Received message on channel: " << channel << endl;
    cout << "Sensor: " << msg->sensor << endl;

    cout << "Current Values: ";
    for (int i = 0; i < sizeof(msg->data); i++) {
        cout << msg->data[i] << ", ";
    }
    cout << endl;
    
    cout << "Units: " << msg->units << endl;
    time_t current_comm_time; 

    // Update the current time 
    time(&current_comm_time); 

    cout << "Time received: " << current_comm_time << endl;
}

// void TMPcallbackHandler(const zcm_recv_buf_t* rbuf, const char* channel, const channel_array* msg, void* user) {
//     // Get the pointer to the channel
//     string channelString(channel);
//     Channel* channelObj = channel_map[channelString];
//     cout << "Received message on channel: " << channelString << endl;

//     // TODO: Should we return some ENUM here?
//     if (channelObj == NULL) {
//         return;
//     }
    
//     channelObj->current_values.clear();
//     channelObj->current_values.insert(channelObj->current_values.begin(), msg->data, msg->data + msg->sz);

//     time(&channelObj->last_comm_time);

//     cout << "Current Values: ";
//     for (int i = 0; i < channelObj->current_values.size(); i++) {
//         cout << channelObj->current_values.at(i) << ", ";
//     }
//     cout << endl;
    
//     cout << "Units: " << msg->units << endl;
//     cout << "Time received: " << channelObj->last_comm_time << endl;
// }

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
    Channel SPT("SPT", (string) serial_port, (string) "ARDUINO1", 0, 1000);
    Channel TMP("TMP", (string) serial_port, (string) "ARDUINO1", 0, 1000); 

    SPT.subscribeToChannel();
    TMP.subscribeToChannel();

    // channel_array_subscribe(SPT.getZCM(), "ARDUINO1", &SPTcallbackHandler, NULL);
    // channel_array_subscribe(TMP.getZCM(), "TMP", &TMPcallbackHandler, NULL);

    // SPT.subscribeToChannel();
    // TMP.subscribeToChannel();

    while (true) {
        for (auto it : channel_map) {
            Channel* channel = it.second;
            zcm_handle_nonblock(channel->getZCM());
        }
    }

    return 0;
}