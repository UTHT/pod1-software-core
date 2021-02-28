#include <SPI.h>            // Not exactly sure if we need this include
#include <Ethernet3.h>      // EthernetUdp3.h does include Ethernet3.h, so this can be removed
#include <EthernetUdp3.h>

#define ARRAY_SIZE 32

// Multicast IP Address
IPAddress multicastIP(239, 0, 0, 57);
uint16_t localPort = 8888;

// Define a MAC address and IP address for sender Arduino
// (Does not need to be that calculated MAC address)
byte mac[] = { 0x0, 0xA2, 0xDA, 0x1D, 0x91, 0xE3 };
IPAddress receiverIPAddress(192, 168, 1, 187);

// Send and receive packets over UDP
EthernetUDP Udp;

// Buffer for receiving data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];

void setup() {
  Serial.begin(115200);
  Serial.println("Starting the serial monitor...");

  // Wait for the serial monitor to start
  while (!Serial) {}

  Ethernet.begin(mac, receiverIPAddress);

  // Start the local multicast server
  if (Udp.beginMulticast(multicastIP, localPort) == 0) {
      Serial.println("Failed to configure UDP Multicast.");
  }
}

void loop() {
  // Check if there is a packet 
  Serial.println("Checking to see if there is a packet to read...");
  int packetSize = Udp.parsePacket();

  if (packetSize) {
      // Print the packet size to serial
      packetSize = packetSize - 8;
      Serial.print("Received packet of size ");
      Serial.println(packetSize);

      // Read contents of the packet
      Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
      Serial.println("Contents:");
      Serial.println(packetBuffer);
  }

  delay(10);
}
