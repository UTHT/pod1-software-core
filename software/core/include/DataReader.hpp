#ifndef DATAREADER_H
#define DATAREADER_H

#include <sys/time.h>
#include <stdbool.h>
#include "Channel.hpp"

class DataReader{
  private:
    Channel channel;
  public:
    DataReader();
    ~DataReader();
    /*TODO: Decide whether using default params or diff paramter
      defs is the way to go. IE, either use def as defined below
      in the uncommented code or as follows:
        bool get() -> non-blocking
        bool get(const struct timeval timeout) -> blocking, with timeout*/

    // a negative timeout waits forever
    // TODO, technically, the blocking bool isn't necessary either
    //  a timeout = 0 means non-blocking, a timeout > 0 means block for whatever
    //  time, and a timeout < 0 means block forever
    bool get(const bool blocking = false,
             const struct timeval timeout ={0});
    bool pub(const bool blocking = false,
             const struct timeval timeout ={0});
};
#endif
