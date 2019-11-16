#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

class Channel{
  private:
    // Channel channel;
    std::string name;
  public:
    Channel();
    Channel(const std::string name);
    virtual ~Channel();

    // TODO: Populate the function parameters. Unclear still.
    // for get
    //    problem: get is really a function handler, or should take as input a function handler
    // for pub
    //    problem: what is the parameter?, as lcmtypes are not inherited, and each type
    //    is a custom class
    bool get();
    bool pub();
};
#endif
