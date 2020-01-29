#ifndef BRAKECONTROLLER_H
#define BRAKECONTROLLER_H

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Channel.hpp"
#include "Controller.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"

class BrakeController : public Controller {
  public:
    
    BrakeController(const struct IOPin io_pin,
                    const States current_state,
                    const std::vector<Channel> channels);

    virtual ~BrakeController();
    // Run through list of channels for updated sensor values and command instructions
    virtual int run() override;
   // ESTOP command
    virtual bool shutdown() override;
};
#endif
