#ifndef HEALTHMONITOR_H
#define HEALTHMONITOR_H

#include <string>
#include <vector>
// We will also need to include some JSON or YAML Reader Library to read the files for channel config data

// Verifies system health and adequate data flow
class HealthMonitor
{
private:
   // Need a vector of ChannelMonitors to iterate through to check if channel is healthy
   // TODO : Change with real class ChannelMonitor class name in Sprint 2
   std::vector<TestChannelMonitor> m_readers; // maybe pointers to readers instead, however this comes with a performance cost

   // Need ENUM variable for current state. For now, it is commented out as we will only consider E-stop until details are hashed out
   // ENUM_STATE m_state;
   bool m_estop;

public:
   /*
      num_channel_monitors : how many channels are to be tested
      path : path to config file 
   */
   HealthMonitor(size_t num_channel_monitors = 0, const std::string &path = "");
   ~HealthMonitor();

   // Describes High Level Functionality
   void run();
};
