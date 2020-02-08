#include <iostream>
#include <unistd.h>
#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"
// #include "lcm_handler.hpp"

channels::practice data;

class LCMHandler{
  public:
    ~LCMHandler(){}
    void handle_message(
        const lcm::ReceiveBuffer* recv_buf,
        const std::string& channel_name,
        const channels::practice* msg){
      data.name = msg->name;
      data.message = msg->message;
      std::cout << "LCMHandler: Message: Handling.";
      std::cout << "LCMHandler: Message: channel name: " << channel_name << std::endl;
      std::cout << "LCMHandler: Message: " << channel_name << ": name: " << msg->name << std::endl;
      std::cout << "LCMHandler: Message: " << channel_name << ": message: " << msg->message << std::endl;
    }
};

int main(int argc, char*argv[]){
  lcm::LCM _lcm;

  if(!_lcm.good())
      return 1;

  std::string channel_name = "practice_channel";

  // Sample
  data.name = "TEST";
  data.message = "TEST";
  LCMHandler lcm_handler;
  _lcm.subscribe(channel_name,
                &LCMHandler::handle_message,
                &lcm_handler);
  std::cout << "Main: Message: Subscribed to " << channel_name << std::endl;


  while(_lcm.handle() == 0){
    std::cout << "NAME: " << data.name << std::endl;
    std::cout << "MESSAGE: " << data.message << std::endl;
  };
  return 0;
}
