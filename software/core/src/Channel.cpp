#include "Channel.hpp"
#include <iostream>

Channel::Channel(){
}
Channel::Channel(const std::string name){
  this->name = name;
}
Channel::~Channel(){
}


bool Channel::get(){

    lcm::LCM lcm;
    if(!lcm.good())
        return false;
  
  return true;

}

bool Channel::pub(const MessageType *msg){
  lcm::LCM lcm;

  lcm.publish((*this).name, msg);

  return true;
}
