#include <lcm/lcm-cpp.hpp>

int main(int argc, char*argv[]){
  lcm::LCM lcm;

  if(!lcm.good())
      return 1;

  /* Your application goes here */

  return 0;
}
