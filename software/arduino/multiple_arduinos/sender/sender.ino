#include <SPI.h>
#include <Ethernet3.h>
#include <EthernetUdp3.h>

#define ARRAY_SIZE 32

byte data1 [ARRAY_SIZE]; // This is the write vector.
byte data2 [ARRAY_SIZE]; // This is the read vector.

// IP address of the sender Arduino
IPAddress ip(111, 111, 111, 222);
uint16_t localPort = 8888;

// Multicast IP address (sender will send data to this)
IPAddress multiIP(239, 0, 0, 57);

// MAC address of the sender Arduino
byte mac[] = {  0x01, 0x00, 0x5E, multiIP[1] & 0x7F, multiIP[2], multiIP[3] };

//mac[3] = multiIP[1] & 0x7F;
//mac[4] = multiIP[2];
//mac[5] = multiIP[3];

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial)
  {
    ; // Wait for serial port to connect. Needed for native USP port only
  }

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    data1[i] = i;
  }

  // Start the Ethernet and UDP:
  Ethernet.begin(mac, ip);
  Udp.begin(localPort);

  if (Udp.beginMulticast(multiIP, localPort)) {
    Serial.println("Successful");
  }

  // print your local IP address:
  Serial.print("My IP Address; ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  Udp.beginPacket(multiIP, localPort);
  Udp.write(data1, ARRAY_SIZE);

  Udp.endPacket();
  Serial.println(data1[0]);
  Serial.println("Data Sent");
  delay(1000);
  data1[0]++;

//   int packetSize = Udp.parsePacket();
//   if (packetSize)
//   {
//     Serial.print("Received packet of size ");
//     Serial.println(packetSize);
//     Serial.print("From ");
//     IPAddress remote = Udp.remoteIP();
//     for (int i = 0; i < 4; i++) 
//     {
//       Serial.print (remote[i], DEC);
//       if (i < 3)
//       {
//         Serial.print(".");
//       }
//     }
//     Serial.print (", port ");
//     Serial.println(Udp.remotePort());

//     // read the packet into packetBuffer
//     Udp.read(data2, ARRAY_SIZE);
//     Serial.println("Contents:");
//     for (int i = 0; i < ARRAY_SIZE; i++)
//     {
//       Serial.print(" ");
//       Serial.print(data2[i]);
//     }
//     Serial.println("");
//     data1[0]++;
//   }
}
