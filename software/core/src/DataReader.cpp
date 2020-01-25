#include "DataReader.hpp"
#include "sys/time.h"
#include "lcm.h"


//Class DataReader with custom constructor DataReader

//Class DataReader with destructor DataReader
DataReader::~DataReader(){

}

//get member function returning type bool of class DataReader
bool DataReader::get(const struct timeval timeout, int pin, class DataReader sensorName){

  sensorName.setPin(pin);
  struct timeval timeS, timeF;
  struct timezone tz;
  gettimeofday(&timeS, &tz); //get the Start time

  // grab data from sensor i.e. from IMU (to be inserted soon)

  gettimeofday(&timeF, &tz); // get the final time
  long int secElapsed = timeF.tv_sec - timeS.tv_sec;
  long int usecElapsed = timeF.tv_usec - timeS.tv_usec;

  if (secElapsed > timeout.tv_sec || (secElapsed == timeout.tv_sec && usecElapsed > timeout.tv_usec)){
    std::cout << "Took too long to fetch data";
    return (false);
  }

  // if we got the data in time, then set the data in its respective DataReader class
  return true;
  ///
}
//publish member function returning type bool of class DataReader
bool DataReader::pub(const struct timeval timeout){
  /// REPLACE
  // subscribe to a channel here

  return true; 
  ///
}

