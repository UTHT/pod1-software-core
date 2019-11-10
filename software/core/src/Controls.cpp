//#include <lcm/lcm-cpp.hpp>
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  //#include "WProgram.h"
#endif

#include <stdio.h>
#include "../include/Controls.hpp"

Controller::Controller(int initialState, int totalStates, String* StateNames, String* ChannelNames, int totalChannels) {

    if (TotalStates >= 1 && TotalStates > initialState) {
        
        currentState = initialState;
        TotalStates = totalStates;
    }
    // TODO
    //else {ERROR HANDLING}

    if (totalChannels >= 1) {TotalChannels = totalChannels;}
    //else {ERROR HANDLING}

    States = new String[TotalStates];
    Channels = new String[TotalChannels];

    for (int i = 0; i < TotalStates; i++) {

        States[i] = StateNames[i];
    }

    for (int i = 0; i < TotalChannels; i++) {

        Channels[i] = ChannelNames[i];
    }

    // Start Communications stuff
}

Controller::~Controller() {

    delete States;
    delete Channels;
}

int Controller::StateChange(String StateName) {

    for (int i = 0; i < TotalStates; i++) {
        if (StateName == States[i]) {
            currentState = i;
            return 0;
        }
    }
    return -1;
}