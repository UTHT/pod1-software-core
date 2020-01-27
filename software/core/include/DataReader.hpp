#ifndef DATAREADER_H
#define DATAREADER_H

#include <sys/time.h>
#include <stdbool.h>
#include <string>

#include "helper/IOPin.hpp"
#include "Channel.hpp" // To be implemented by Sabita and Shaziah

class DataReader{
  private:
    struct IOPin io_pin;
    Channel channel;
  public:
    DataReader();
    ~DataReader();
    //  a timeout = 0 means non-blocking, a timeout > 0 means block for whatever
    //  time, and a timeout < 0 means block forever
    bool get(const std::string chanel_name,
             const struct timeval timeout = {0});
    bool pub(const struct timeval timeout = {0});
};
#endif
