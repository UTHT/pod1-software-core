#ifndef SM_H
#define SM_H
#include <tinyfsm.hpp>

// Event Declarations

struct HEALTH_fail : tinyfsm::Event { };
struct LAUNCH_cmd : tinyfsm::Event{ };
struct ON_cmd : tinyfsm::Event{ };
struct BRAKE_cmd : tinyfsm::Event{ };
struct END_OF_TRACK : tinyfsm::Event{ };
struct COMPLETE_STOP : tinyfsm::Event{ };

// State Machine Base Class Declaration
class SM : public tinyfsm::Fsm<SM>
{
  public:
  virtual void react(HEALTH_fail const &) { };
  virtual void react(LAUNCH_cmd const &) { };
  virtual void react(ON_cmd const &) { };
  virtual void react(BRAKE_cmd const &) { };
  virtual void react(END_OF_TRACK const &) { };
  virtual void react(COMPLETE_STOP const &) { };



  virtual void entry(void) { };  /* entry actions in some states */
  virtual void exit(void)  { };  /* no exit actions */
};

#endif