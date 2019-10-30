#pragma once

#include <string>
#include <vector>
/*The data reader(s) are an ideal way of maintaining a growing
nummber of channels.*/
#include "helpers/DataReader.hpp"
//#include "SOME_JSON_READER"

// Verifies system health and adequate data flow
class HealthMonitor
{
private:
   /*Some form of JSON or yaml approach to feeding the data
   needed to generate the data readers*/
   std::vector<DataReader> m_readers; // maybe pointers to readers instead, however this comes with a performance cost
   // ENUM_STATE m_state;
   bool m_estop; // only considering e-stop state for now
private:
   /*Using a json reader library import the channel-data and generate
   the data-readers vector*/
   void generate_readers(const std::string &path)
   {
      int FILE = 0;
      for (size_t i = 0; i < FILE; i++)
      {
         // fill m_readers with each iteration
      }
   }

public:
   HealthMonitor(size_t numDataReaders = 0, const std::string &path = "")
   {
      // reserve the room required rather than expanding the structure each insert
      m_readers.reserve(numDataReaders); // potentially use .resize instead for simplicity
      generate_readers(path);
   }
   ~HealthMonitor();

   // high-level functionality
   void run()
   {
      // iterate the data readers
      for (auto &reader : m_readers)
      {
         // update state
         if (!reader.get_state())
         {
            m_estop = true;
            // no need to check other readers if one is bad
            break;
         }
      }
      // enable estop if true
   }
};
