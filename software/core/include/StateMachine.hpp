#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "helper/enums.hpp"

class StateMachine {
  private:
    States current_state;
  public:
  StateMachine();
  ~StateMachine();
  void run();
};

#endif
