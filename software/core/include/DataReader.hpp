#ifndef DATAREADER_H
#define DATAREADER_H

#include <sys/time.h>
#include <stdbool.h>
#include "helper/IOPin.hpp"
#include "Channel.hpp" // To be implemented by Sabita and Shaziah

class DataReader{
  private:
    // Channel channel;
    struct IOPin io_pin;
  public:
    DataReader();
    ~DataReader();
    //  a timeout = 0 means non-blocking, a timeout > 0 means block for whatever
    //  time, and a timeout < 0 means block forever
    bool get(const struct timeval timeout ={0});
    bool pub(const struct timeval timeout ={0});
};
#endif
