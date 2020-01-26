#include "Channel.hpp"
#include <iostream>

Channel::Channel(){
  std::cout << "TEST" << std::endl;
}
Channel::Channel(const std::string name){
  this->name = name;
}
Channel::~Channel(){
}


bool Channel::get(){
  /// REPLACE
  return true;
  ///
}

bool Channel::pub(){
  /// REPLACE
  return true;
  ///
}
