//Header file for Channel Handler

#include <iostream>
#include <string>
#include <vector>
#include "../../channels/channel.hpp"
#include "../../channels/enums.hpp"
#include "../../libraries/zcm_types/src/zcm_msg.h"

using namespace std;
       
std::vector<Channel> subscribeToChannels();  
        // ChannelHandler(vector<Channel> channels);