#include <iostream>
#include <cpprest/ws_client.h>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include<unistd.h>

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

    out_msg.set_utf8_message("{ 'isNew':1 }");
    client.send(out_msg).wait();

    std::ifstream file("testFiles/speedIncrease_2.txt");

    //std::ifstream file("input.txt");
    
    std::string str;
    while (std::getline(file, str)) {
      std::cout << str << "\n";
      char *text = new char[str.length() + 1];
      strcpy(text, str.c_str());

       //cout << text2 << endl;
      out_msg.set_utf8_message(text);
      //data.replace(/'/g, '"'); -- Important
      client.send(out_msg).wait();
      delete[] text;
      sleep(1);
    }
    

   

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