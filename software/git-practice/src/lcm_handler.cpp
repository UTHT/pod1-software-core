#include <stdio.h>
#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"

class LCMHandler{
  public:
    ~LCMHandler(){}
    void handle_message(
        const lcm::ReceiveBuffer* recv_buf,
        const std::string& channel_name,
        const channels::practice* msg){
      std::cout << "LCMHandler: Message: channel name: \"%s\"", \
        channel_name << std::endl;
      std::cout << "LCMHandler: Message: \"%s\": name: %s", \
        channel_name, msg->name << std::endl;
      std::cout << "LCMHandler: Message: \"%s\": message: %d", \
        channel_name, msg->message << std::endl;
    }
}
