#include <iostream>
#include <cpprest/ws_client.h>

using namespace std;
using namespace web;
using namespace web::websockets::client;

int main() {
  try {
    websocket_client client;
    client.connect("ws://127.0.0.1:8080/").wait();
    websocket_outgoing_message out_msg;
    out_msg.set_utf8_message("{'msg':'Message from Server', 'name':'serverB'}");
    //data.replace(/'/g, '"'); -- Important
    client.send(out_msg).wait();

    client.receive().then([](websocket_incoming_message in_msg) {
      return in_msg.extract_string();
    }).then([](string body) {
      cout << body << endl; // test
    }).wait();

    client.close().wait();
  } catch (int e) {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
  }

  return 0;
}