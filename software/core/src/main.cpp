#include "Channel.hpp"
#include "ChannelMonitor.hpp"
#include "DataReader.hpp"
#include "HealthMonitor.hpp"
#include "NetworkMonitor.hpp"
#include "helper/enums.hpp"
#include "helper/IOPin.hpp"

int main(int argc, char* argv[]){
  Channel channel();
  ChannelMonitor channel_monitor();
  DataReader data_reader();
  HealthMonitor health_monitor();
  NetworkMonitor network_monitor();
}
