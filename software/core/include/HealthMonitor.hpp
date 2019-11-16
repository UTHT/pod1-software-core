#ifndef HEALTHMONITOR_H
#define HEALTHMONITOR_H

#include <string>
#include <vector>

#include "ChannelMonitor.hpp"
// We will also need to include some JSON or YAML Reader Library to read the files for channel config data

class HealthMonitor{
  private:
   std::vector<ChannelMonitor> channel_monitors; // maybe pointers to readers instead, however this comes with a performance cost

   // TODO (Mathieu) Why is the below necessary? Confused.
   // Need ENUM variable for current state. For now, it is commented out as we will only consider E-stop until details are hashed out
   // ENUM_STATE m_state;
   // bool m_estop;

  public:
   // For testing
   HealthMonitor();
   HealthMonitor(const std::string &file_name);
   ~HealthMonitor();

   // Describes High Level Functionality
   void run();
};
#endif
