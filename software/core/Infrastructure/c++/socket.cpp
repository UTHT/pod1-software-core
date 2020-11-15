#include <iostream>
#include <cpprest/ws_client.h>

using namespace std;
using namespace web;
using namespace web::websockets::client;

int main() {
  websocket_client client;
  if (client.connect("ws://127.0.0.1:8080/").wait() < 0){
    return -1;
  }
  else{
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
  }
  return 0;
}