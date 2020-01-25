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
  // struct info = channel.handle();

  // Check value 
  if(info.value == NULL) {
    return ChannelStatus::NO_VALUE;
  } else if(info.value < min_value || info.value > max_value) {
    return ChannelStatus::OUT_OF_RANGE;
  } 

  if(info.rtt > max_rtt) {
    return ChannelStatus::HIGH_FREQUENCY;
  } else if(info.rtt < min_rtt) {
    return ChannelStatus::LOW_FREQUENCY;
  }

  return ChannelStatus::FUNCTIONING;
}

bool ChannelMonitor::publish(){
  // Not sure where the MessageType class is defined to create the message 
  // variable. (Channel publish method has one MessageType argument)

  int current_status = check();
  // MessageType msg;

  if(current_status == ChannelStatus::FUNCTIONING) {
    msg = "Functioning";
  } else {
    msg = "Malfunctioning"
  }

  return channel.pub(&msg);
}

