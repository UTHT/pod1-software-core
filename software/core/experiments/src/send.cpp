#include <iostream>
#include <unistd.h>
#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"
// #include "lcm_handler.hpp"

int main(int argc, char*argv[]){
  lcm::LCM _lcm;

  if(!_lcm.good())
      return 1;

  channels::practice practice_data;
  std::string channel_name = "practice_channel";

  practice_data.name = "Mathieu Tuli";
  practice_data.message = "C++ LCM Example.";
  int count = 0;
  for(;;){
    std::cout << "Main: Message: count: " << count++ << std::endl;
    std::cout << "Main: Message: Creating Message" << std::endl;
    _lcm.publish(channel_name, &practice_data);
    std::cout << "Main: Message: Message published" << std::endl;
    usleep(2000000);
  };
  return 0;
}
