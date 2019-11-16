#include "ChannelMonitor.hpp"
#include "Channel.hpp"

ChannelMonitor::ChannelMonitor(){
}
ChannelMonitor::ChannelMonitor(
    const Channel channel,
    const double min_value, const double max_value,
    const double min_rtt, const double max_rtt){
}
ChannelMonitor::~ChannelMonitor(){
}

int ChannelMonitor::check(){
  /// REPLACE
  return 0;
  ///
}

bool ChannelMonitor::publish(){
  /// REPLACE
  return true;
  ///
}

