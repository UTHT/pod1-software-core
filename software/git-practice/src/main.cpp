#include <lcm/lcm-cpp.hpp>
#include "channels/practice.hpp"
#include "lcm_handler.hpp"

int main(int argc, char*argv[]){
  lcm::LCM lcm;

  if(!lcm.good())
      return 1;

  channels::practice practice_data;
  std::string channel_name = "practice_channel";

  // Sample
  practice_data.name = "Mathieu Tuli";
  practice_data.message = "Practicing some GIT";
  lcm.publish(channel_name, &practice_data);
  // End of sample

  // Create your own here!
  // *******************

  LCMHandler lcm_handler;
  lcm.subscribe(channel_name,
                &LCMHandler::handle_message,
                &lcm_handler);

  while(lcm.handle() == 0);
  return 0;
}
