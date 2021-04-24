#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <test_msg.h>

zcm_t* zcm_arduino;
int counter;

void setup() {
  // put your setup code here, to run once:
  zcm_arduino = create_zcm(0);
  counter = 0;
}

int publishTestToChannel(zcm_t* zcm, String msg, String channel) {  
  test_msg message;
  message.str = (char *) msg.c_str();

  return test_msg_publish(zcm, channel.c_str(), &message);
}

void loop() {
  String message = "This is a test message: " + String(counter);

  // Might not need to include this. Arduino was able to publish 
  // with or without this.
  zcm_handle_nonblock(zcm_arduino);

  // The "send" method in PacketSerialArduino writes an encoded
  // version of the message to the serial monitor. The Linux side
  // of ZCM reads this message (aka the Odroid).
  int result = publishTestToChannel(zcm_arduino, message, "TEST");

  // Need to remove this after testing
  Serial.println();

//  if (result == 0) {
//    Serial.println("Successfully published to channel 'TEST'");
//  } else {
//    Serial.println("Error");
//  }

  counter++;
  delay(2000);
}
