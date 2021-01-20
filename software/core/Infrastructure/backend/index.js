const { Socket } = require('dgram');
const WebSocket = require('ws');

const JSONParser = require('./externalSocketParser/parser');
const digest  = require('./Digester/index');
const encapsulate = require('./Encapsulate/index');


const wss = new WebSocket.Server({ port: 8080 });
var clientList = [];


//websocket connection
wss.on('connection', function connection(ws) {
  //websocket message
  ws.on('message', function incoming(data) {

    // parsed incoming data from sockets
    var parsedData = JSONParser(data);

    // if the socket is just connected, add it to the client list
    if (parsedData.isNew) {

      parsedData["socket"] = ws;
      clientList.push(parsedData);

    }
    else {
      clientList.forEach(function each(client) {
        if (client.socket.readyState === WebSocket.OPEN) {
          if (parsedData.serverType == 'odroid') {
            
            var error = [];

            // validation module -- here
            console.log("Parsed Data \n")
            console.log(parsedData);
            // Divide incoming data into multiple components
            var Digestor =  digest(parsedData);

            console.log("Digestor Data \n");
            console.log(Digestor);

            // pack all the data to be sent to front-end.
            var encapsulator = encapsulate(Digestor, error);

            console.log("Encapsulator Data \n");
            console.log(encapsulator);

            // Send encapsulation data to front-end
            clientList.forEach((elem) => {
              if (elem.serverType == 'dashboard') {
                elem.socket.send(JSON.stringify(encapsulator));
              }
            });

          }

          else {

            // Send encapsulation data to odroid
            clientList.forEach((elem) => {
              if (elem.serverType == 'odroid') {
                elem.socket.send(JSON.stringify(Encapsulation));
              }
            });

          }

        }
      });
    }

  });
});