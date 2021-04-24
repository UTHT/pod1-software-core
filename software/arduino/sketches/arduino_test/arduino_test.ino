#include <zcm_utht.h>
#include <transport.h>
#include <arduino_cobs_serial_transport.hpp>
#include <test_msg.h>

zcm_t* zcm_arduino;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  zcm_arduino = create_zcm(1);
}

int publishTestToChannel(zcm_t* zcm, String msg, String channel) {  
  test_msg message;
  message.str = (char *) msg.c_str();

  test_msg_destroy(&message);

  return test_msg_publish(zcm, channel.c_str(), &message);
}

void loop() {
  // put your main code here, to run repeatedly:
  String message = "This is a test message";

  

  int result = publishTestToChannel(zcm_arduino, message, "TEST");

  if (result == 0) {
    Serial.println("Successfully published to channel 'TEST'");
  } else {
    Serial.println("Error");
  }

}
