#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <stdio.h>
#include <vector>

#include "State.hpp"
#include "Channel.hpp"
#include "Controller.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"

class MotorController : public Controller {
  public:
    
    MotorController(const struct IOPin io_pin,
                    const States current_state,
                    const std::vector<Channel> channels);

    virtual ~MotorController();
    // Run through list of channels for updated sensor values and command instructions
    virtual int run() override;
   // ESTOP command
    virtual bool shutdown() override;
};
#endif
