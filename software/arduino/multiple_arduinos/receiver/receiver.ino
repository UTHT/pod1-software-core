#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet3.h>
#include <EthernetUdp3.h>         
 
// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:

// CHANGE THIS FOR THE TWO RECEIVER ARDUINOS
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(111, 111, 111, 111);

// Local port to listen to incoming packets from
uint16_t localPort = 8888;  

// Multicast
IPAddress ipMulti(239, 0, 0, 57);
 
// the next two variables are set when a packet is received
byte remoteIp[4];        // holds received packet's originating IP
unsigned int remotePort; // holds received packet's originating port 
 
// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back
EthernetUDP Udp;

void setup() {
  
  Serial.begin(115200);
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);

  // Debug printing for multi cast
  Serial.println("Entering Multi-Cast");
  
  // multicast UDP
  //Udp.begin(localPort);
  if (Udp.beginMulticast(ipMulti, localPort)) {
    Serial.println("Successful");
  }
  else {
    Serial.println("Failure");
  }
 
}
 
void loop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket(); // note that this includes the UDP header
  if(packetSize)
  {
    packetSize = packetSize - 8;      // subtract the 8 byte header
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
 
    // read the packet into packetBufffer and get the senders IP addr and port number
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);
    // Udp.sendPacket( ReplyBuffer, remoteIp, remotePort);
  }
  delay(10);
}
