//Header file for Channel Handler

#include <iostream>
#include <string>
#include <vector>
#include <channel.hpp>

using namespace std;


bool subscribeToChannels(char *serial_port);
void add_to_channel(Channel temp);
void populate_channel_map();

// ChannelHandler(vector<Channel> channels);