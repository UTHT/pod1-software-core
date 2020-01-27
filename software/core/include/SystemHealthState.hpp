#ifndef SYSTEMHEALTHSTATE_H
#define SYSTEMHEALTHSTATE_H
#include <iostream>
#include <string>
#include <vector>

#include "CommunicationCheckState.hpp"
#include "HealthMonitor.hpp"
#include "NetworkMonitor.hpp"
#include "DataReader.hpp"
#include "State.hpp"
#include "helper/enums.hpp"
//add states enum.hpp

class SystemHealthState: public State{
  private:
    std::vector<HealthMonitor> health_monitor;

	public:
	  SystemHealthState(States name);
	  ~SystemHealthState();
    States run();

};
#endif
