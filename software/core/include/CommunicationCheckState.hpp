#ifndef COMMUNICATIONCHECKSTATE_H
#define COMMUNICATIONCHECKSTATE_H
#include <iostream>
#include <string>

#include "Channel.hpp"
#include "ChannelMonitor.hpp"
#include "NetworkMonitor.hpp"

class CommunicationCheckState{
	private:
		Channel channel;
		//list the channels that needs to be checked for sufficient conditions
	public:
		CommunicationCheckState(Channel channel);
		~CommunicationCheckState();
		//function of the this state??
		void comms_check();
		void run(); //Send Check=1 signal to SystemHealthState 
};
#endif
