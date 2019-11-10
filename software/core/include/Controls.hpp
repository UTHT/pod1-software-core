#ifndef controller_h
#define controller_h
#include <stdio.h>
#include "../lib/Arduino-PID-Library/PID_v1.h"

// TODO: Need to add functionality if sensors measurements occur with the same Arduino
// Sensor class?

class Controller {
    private:

        // Current Controller State
        int currentState = 0;
        int TotalStates = 0;

        // Controller States
        String* States = nullptr;

        int TotalChannels = 0;
        String* Channels = nullptr;
        // For now String array, later would be array of comm objects
        // where the remaining comms stuff would be handed off to the comms class

        // comms class object

    public:

        Controller(int initialState, int totalStates, String* StateNames, String* ChannelNames, int totalChannels);

        ~Controller();

        int StateChange(String StateName);

        virtual int run();

        virtual bool shutdown();
};
#endif