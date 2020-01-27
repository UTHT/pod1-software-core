#ifndef COMMUNICATIONCHECKSTATE_H
#define COMMUNICATIONCHECKSTATE_H
// #include <iostream>
// #include <string>
#include <vector>

// #include "ChannelMonitor.hpp"
// #include "NetworkMonitor.hpp"
#include "Channel.hpp"
#include "helper/enums.hpp"

class CommunicationCheckState{
	private:
    std::vector<Channel> channels;
		//list the channels that needs to be checked for sufficient conditions
	public:
		CommunicationCheckState(std::vector<Channel> channels);
		~CommunicationCheckState();
		//function of the this state??
		States run(); //Send Check=1 signal to SystemHealthState
};
#endif
