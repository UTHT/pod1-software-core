#include "CommunicationCheckState.hpp"

CommunicationCheckState::CommunicationCheckState(std::vector<Channel> channels){
}

CommunicationCheckState::~CommunicationCheckState(){
}

States CommunicationCheckState::run(){
	//if k=n,Go to SystemHealthCheck
	//state = SysCheck
	//else
	//state = CommsCheck
  return COMMS_CHECK;
}
