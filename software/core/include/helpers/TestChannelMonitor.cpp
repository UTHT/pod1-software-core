#pragma once

#include <string>

// Processes singular channels
class TestChannelMonitor
{
private:
   // arbritrary data types
   // channel name
   std::string m_channel;

   // enumerated states
   // ENUM_CLASS m_state;
   bool m_state;

   // potentially important
   double m_frequency = 0;
   double m_bandwidth = 0;
   unsigned int m_bytes = 0;

   // tolerance ranges
   double m_tolFrequency;
   double m_tolBandwidth;
   unsigned int m_tolBytes;

protected:
   template <typename T>
   const bool in_tolerance(T data, T range) const
   {
      return !(data < data - range || data > data + range);
   }

public:
   TestChannelMonitor(
       double tolFrequency = 0,
       double tolBandwidth = 0,
       unsigned int tolBytes = 0);
   ~TestChannelMonitor();

   // returns the state of the data readers
   bool get_state()
   {
      update_state();
      return m_state;
   }

   // update the state of the channel
   void update_state()
   {
      m_state = in_tolerance(m_frequency, m_tolFrequency) && in_tolerance(m_bandwidth, m_tolBandwidth) && in_tolerance(m_bytes, m_tolBytes);
   }

   // if dynamic updating of tolerance ranges is required
   void update_tolerance();
};
