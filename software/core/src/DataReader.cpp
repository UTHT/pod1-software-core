#include "DataReader.hpp"
#include "sys/time.h"
#include "lcm.h"

DataReader::DataReader(){
}

DataReader::~DataReader(){

}

// will populate some member var, return value says if updated or not
bool DataReader::get(const std::string channel_name,
                     const struct timeval timeout){
  /// REPLACE
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

