#include <SPI.h>            // Not exactly sure if we need this include
#include <Ethernet3.h>      // EthernetUdp3.h does include Ethernet3.h, so this can be removed
#include <EthernetUdp3.h>

#define ARRAY_SIZE 32

// Multicast IP Address
IPAddress multicastIP(239, 0, 0, 57);
uint16_t localPort = 8888;

// Define a MAC address and IP address for sender Arduino
// (Does not need to be that calculated MAC address)
byte mac[] = { 0x0, 0xA2, 0xDA, 0x0D, 0x90, 0xE2 };
IPAddress senderIPAddress(192, 168, 1, 177);

// Send and receive packets over UDP
EthernetUDP Udp;

// Define byte to send
byte data;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting the serial monitor...");
  
  // Wait for the serial monitor to start
  while (!Serial) {}

  Ethernet.begin(mac, senderIPAddress);
  
  // Start the local multicast server
  if (Udp.beginMulticast(multicastIP, localPort) == 0) {
    Serial.println("Failed to configure UDP Multicast.");
  }

  // Initialize data
  data = 0;
}

void loop() {
  // Send data to the multicast IP address
  Udp.beginPacket(multicastIP, localPort);
  Udp.write(data);
  Udp.endPacket();

  Serial.println("Sending data...");
  Serial.println(data);

  data++;

  delay(1000);
}
