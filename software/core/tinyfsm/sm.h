#ifndef SM_H
#define SM_H
#include <tinyfsm.hpp>

// Event Declarations

struct HEALTH_fail : tinyfsm::Event { };
struct LOCK_cmd : tinyfsm::Event { };
struct ARM_cmd : tinyfsm::Event { };

// State Machine Base Class Declaration
class SM : public tinyfsm::Fsm<SM>
{
  public:
  virtual void react(HEALTH_fail const &) { };
  virtual void react(LOCK_cmd const &) { };
  virtual void react(ARM_cmd const &) { };

  virtual void entry(void) { };  /* entry actions in some states */
  void         exit(void)  { };  /* no exit actions */
};

#endif