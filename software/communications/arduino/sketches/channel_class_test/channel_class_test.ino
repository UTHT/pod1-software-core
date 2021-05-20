#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <channel_msg.h>

zcm_t* zcm_arduino;
int counter;

void setup() {
  // put your setup code here, to run once:
  zcm_arduino = create_zcm(0);
  counter = 0;
}

int publishTestToChannel(zcm_t* zcm, int value, String channel) {  
  channel_msg message;
  message.arduino_id = 1;
  message.sensor_id = 2;
  message.sensor_value = value;

  return channel_msg_publish(zcm, channel.c_str(), &message);
}

void loop() {
  zcm_handle_nonblock(zcm_arduino);

  // The "send" method in PacketSerialArduino writes an encoded
  // version of the message to the serial monitor. The Linux side
  // of ZCM reads this message (aka the Odroid).
  int result = publishTestToChannel(zcm_arduino, counter, "test_sensor");

//  if (result == 0) {
//    Serial.println("Successfully published to channel 'TEST'");
//  } else {
//    Serial.println("Error");
//  }

  counter++;
  delay(200);
}
