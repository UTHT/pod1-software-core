#include "SystemHealthState.hpp"
using namespace std;
SystemHealthState::SystemHealthState(States name) : State(name){

}

SystemHealthState::~SystemHealthState(){
}

States SystemHealthState::run(){
  //for(int i = 0;i< States name.size();i++)
  //{
  //	if(min_valuee<name[i]<max_value)
  //	{
  //	int j++ (count for healthy states)
  //	return j;
  //	}
  //	else
  //	{
  //	cout<< "State"<<i<<"is unstable.";
  //	k++(count for unstable states)
  //	return k;
  //	}
  //cout<<"Healthy States:"<<j<<"\n Unhealthy States:"<<k<<endl; 
  //}
  //if (k=names.size) i.e all states are healthy
  //{
  // GOTO ARM STATE
  // cout<<"System is healthy!!"<<endl;
  //}
  //else
  //{
  //GOTO DEBUG STATE;
  //}
  return SYS_CHECK;
}

