#ifndef HM_H
#define HM_H

#include "en.hpp"

class HealthMonitor {
  public:
    bool health_status = true;
    void healthCheck();
};

#endif