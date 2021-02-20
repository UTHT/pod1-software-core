#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#define ARRAY_SIZE 32

byte data1 [ARRAY_SIZE]; // This is the write vector.
byte data2 [ARRAY_SIZE]; // This is the read vector.

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.

byte mac[] = {0x11, 0x11, 0x11, 0x11, 0x11, 0x11}; // This is the local board number 1.
IPAddress ip(111, 111, 111, 222);
unsigned int localPort = 22222;

char multi_IP[] = "239.0.0.57"; // This is the foreign board number 2.
int multi_Port = 12345;

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

  // print your local IP address:
  Serial.print("My IP Address; ");
  Serial.println(Ethernet.localIP());
}

void loop()
{
  Udp.beginPacketMulticast(multi_IP, multi_Port);
  Udp.write(data1, ARRAY_SIZE);

  Udp.endPacket();

  delay(1000);

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
