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
//add states enum.hpp

class SystemHealthState:public State{
		private:
	        States name,
		//The data pertaining to the system.
		//Get the data from data reader and health monitor
                std::vector<HealthMonitor> health_monitors;
		
		public:
		SystemHealthState();
		~SystemHealthState();
		void sys_check();
		//if sys_check=1, go to arm state
		//elseif sys_check=0, go to debug state
		void run(); 
};
#endif
