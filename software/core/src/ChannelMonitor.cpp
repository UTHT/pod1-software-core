#include "ChannelMonitor.hpp"
#include "Channel.hpp"

ChannelMonitor::ChannelMonitor(){
}
ChannelMonitor::ChannelMonitor(
    const Channel channel_init,
    const double min_value_init, const double max_value_init,
    const double min_rtt_init, const double max_rtt_init){
      channel = channel_init;
      min_value = min_value_init;
      max_value = max_value_init;
      min_rtt = min_rtt_init;
      max_rtt = max_rtt_init;
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

