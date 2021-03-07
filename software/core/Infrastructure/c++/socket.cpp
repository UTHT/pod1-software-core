#include <iostream>
#include <cpprest/ws_client.h>
#include "./classes/sensor.h"
#include <vector>

using namespace std;
using namespace web;
using namespace web::websockets::client;

int main()
{
  try
  {
    websocket_client client;
    client.connect("ws://127.0.0.1:8080/").wait();
    websocket_outgoing_message out_msg;

    out_msg.set_utf8_message("{ 'eventType':'connection','data':{'clientType':'odroid'},'isNew':1 }");
    client.send(out_msg).wait();

//Example class usage
    //Sensor _sensor = new Sensor {"k", 90};
    SpeedSensor sp{"speed", 200};
    TemperatureSensor tp1 {"motor", 100};
    TemperatureSensor tp2 {"brake", 150};
    BatterySensor b1 {"battery", 40};
    BatterySensor b2 {"battery", 50};
    BrakeSensor br1 {"left", 140};
    BrakeSensor br2 {"ight", 60};
    PositionSensor p1 {12,16};

    vector<SpeedSensor> vsp;
    vsp.push_back(sp);

    vector<TemperatureSensor> tp;
    tp.push_back(tp1);
    tp.push_back(tp2);

    vector<BatterySensor> b;
    b.push_back(b1);
    b.push_back(b2);

    vector<BrakeSensor> br;
    br.push_back(br1);
    br.push_back(br2);

    Bundler *bundle = new Bundler {vsp, tp, b, br, p1};
    cout << bundle->toString()<< endl;
//Example end

    out_msg.set_utf8_message(bundle->toString());
    client.send(out_msg).wait();

    client.receive().then([](websocket_incoming_message in_msg) {
                      return in_msg.extract_string();
                    })
        .then([](string body) {
          cout << body << endl; // test
        })
        .wait();

    client.close().wait();
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }

  return 0;
}

