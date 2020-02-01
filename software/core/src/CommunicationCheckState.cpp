#include "CommunicationCheckState.hpp"

CommunicationCheckState::CommunicationCheckState(std::vector<Channel> channels){
}

CommunicationCheckState::~CommunicationCheckState(){
}

States CommunicationCheckState::run(){
	//for(int i = 0;i < channels.size() ; i++)
	//{
	//	if(channels.at(i) exists) TODO:Find some function that compares the 	            received signal with a pre-defined list 
	//	{
	//	count the received signals(use j++)
	//	return j;
	//	}
	//	else
	//      {
	//      count the missed channel(use k++)
	//      cout << "Channel " << i << "is not responding."<<endl;
	//      return k;
	//	}
	//}
	//cout <<"Responding channels :"<< j <<"\n Missing channels:"<< k;
  return COMMS_CHECK;
}
