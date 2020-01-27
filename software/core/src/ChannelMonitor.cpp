#include "ChannelMonitor.hpp"
#include "Channel.hpp"

ChannelMonitor::ChannelMonitor(
    const std::string channel_name,
    const double min_value, const double max_value,
    const double min_rtt, const double max_rtt){
      this->channel_name = channel_name;
      this->min_value = min_value;
      this->max_value = max_value;
      this->min_rtt = min_rtt;
      this->max_rtt = max_rtt;
}
ChannelMonitor::~ChannelMonitor(){
}

ChannelStatus ChannelMonitor::check(){
  // struct info = channel.handle();

  // Check value
  // if(info.value == NULL) {
  //   return ChannelStatus::NO_VALUE;
  // } else if(info.value < min_value || info.value > max_value) {
  //   return ChannelStatus::OUT_OF_RANGE;
  // }

  // if(info.rtt > max_rtt) {
  //   return ChannelStatus::HIGH_FREQUENCY;
  // } else if(info.rtt < min_rtt) {
  //   return ChannelStatus::LOW_FREQUENCY;
  // }

  return ChannelStatus::FUNCTIONING;

}

// bool ChannelMonitor::publish(){
//   // Not sure where the MessageType class is defined to create the message
//   // variable. (Channel publish method has one MessageType argument)

//   int current_status = check();
//   // MessageType msg;

//   if(current_status == ChannelStatus::FUNCTIONING) {
//     msg = "Functioning";
//   } else {
//     msg = "Malfunctioning"
//   }

//   return channel.pub(&msg);
// }

