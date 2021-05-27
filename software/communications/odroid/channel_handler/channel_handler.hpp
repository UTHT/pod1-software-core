//Header file for Channel Handler

#include <iostream>
#include <string>
#include <vector>
#include "../../channels/channel.hpp"
#include "../../channels/enums.hpp"
#include "../../libraries/zcm_types/src/zcm_msg.h"
#include <linux_cobs_serial_transport.hpp>

using namespace std;


bool subscribeToChannels(char *serial_port);
void add_to_channel(Channel temp);
void populate_channel_map();

// ChannelHandler(vector<Channel> channels);