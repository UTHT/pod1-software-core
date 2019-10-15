#ifndef DEMOSAIC_H
#define DEMOSAIC_H
#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"

class LCMHandler{
  public:
    ~LCMHandler(){}
    void handle_message(
        const lcm::ReceiveBuffer* recv_buf,
        const std::string& channel_name,
        const channels::practice* msg);
};
#endif
