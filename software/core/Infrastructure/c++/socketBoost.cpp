//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: WebSocket client, synchronous
//
//------------------------------------------------------------------------------

//[example_websocket_client

#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include "./classes/sensor.h"
#include <vector>


namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
using namespace std;

// Sends a WebSocket message and prints the response
int main(int argc, char** argv)
{
    try
    {
        // Check command line arguments.
        if(argc != 3)
        {
            std::cerr <<
                "Usage: websocket-client-sync <host> <port> <text>\n" <<
                "Example:\n" <<
                "    websocket-client-sync echo.websocket.org 80 \"Hello, world!\"\n";
            return EXIT_FAILURE;
        }
        auto const host = argv[1];
        auto const port = argv[2];
        auto const text = "{ 'eventType':'connection','data':{'clientType':'odroid'},'isNew':1 }"; // First data for handshake and connection


        /***
        Initiate Handshake with the websocket server and send the connection string
        **/

        #pragma region Initiate Handshake


        // The io_context is required for all I/O
        net::io_context ioc;

        // These objects perform our I/O
        tcp::resolver resolver{ioc};
        websocket::stream<tcp::socket> ws{ioc};

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        net::connect(ws.next_layer(), results.begin(), results.end());

        // Set a decorator to change the User-Agent of the handshake
        ws.set_option(websocket::stream_base::decorator(
            [](websocket::request_type& req)
            {
                req.set(http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-coro");
            }));

        // Perform the websocket handshake
        ws.handshake(host, "/");

        
        #pragma endregion

        #pragma region Connection string

        // Send the message
        ws.write(net::buffer(std::string(text)));

        // This buffer will hold the incoming message
        beast::flat_buffer buffer;

        // Read a message into our buffer
        ws.read(buffer);


        #pragma endregion

        #pragma region Data stream

        VelocitySensor sp{"velocity", 200};
        TemperatureSensor tp1 {"motor", 100};
        TemperatureSensor tp2 {"brake", 150};
        BatterySensor b1 {"battery", 40};
        BatterySensor b2 {"battery", 50};
        BrakeSensor br1 {"left", 140};
        BrakeSensor br2 {"ight", 60};
        PositionSensor p1 {12,16};

        vector<VelocitySensor> vsp;
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

         ws.write(net::buffer(std::string(bundle->toString())));


        // Read a message into our buffer
        ws.read(buffer);

        #pragma endregion

        

        // Close the WebSocket connection
        ws.close(websocket::close_code::normal);

        // If we get here then the connection is closed gracefully

        // The make_printable() function helps print a ConstBufferSequence

        //std::cout << beast::make_printable(buffer.data()) << std::endl;

    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//]