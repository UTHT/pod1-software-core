#include <iostream>
#include <cpprest/ws_client.h>

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
    
    const char *text2 = "\
           {\
            'serverType':'odroid',\
              'speed':[\
                  {\
                      'name':'speed','value':250\
                  }\
              ],\
              'temperatures':[\
                            {\
                              'name': 'motor','value':56 \
                            },\
                            {'name': 'battery','value':78} \
                            ],\
              'position':[127,46],\
              'brakes':[\
                  {\
                      'name':'brakes_left','status':0,'pressure':257\
                  },\
                  {\
                      'name':'brakes_right','status':0,'pressure':257\
                  }\
              ],\
              'battery':[\
                  {\
                      'name':'battery_1','value':67\
                  },\
                  {\
                      'name':'battery_2','value':64\
                  }\
              ]\
          }\
        ";
    

    cout << text2 << endl;
    out_msg.set_utf8_message(text2);
    //data.replace(/'/g, '"'); -- Important
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