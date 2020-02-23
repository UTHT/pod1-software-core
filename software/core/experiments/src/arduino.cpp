#include <SPI.h>
#include <Ethernet.h>

// network configuration. dns server, gateway and subnet are optional.

 // the media access control (ethernet hardware) address for the shield:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// the computer ip address
IPAddress dnServer(192, 168, 0, 1);
// the router's gateway address:
IPAddress gateway(192, 168, 0, 1);
// the subnet:
IPAddress subnet(255, 255, 255, 0);

//the IP address is dependent on your network
IPAddress ip(192, 168, 0, 2);

void setup() {
  Serial.begin(9600);

  // initialize the ethernet device
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  //print out the IP address
  Serial.print("IP = ");
  Serial.println(Ethernet.localIP());
}

void loop() {
}
