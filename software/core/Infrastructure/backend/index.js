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
      console.log("isNew");
    }
    else {


      // clientList.forEach((element) => {
      //   //if unique ID match, changee element.serverType to parsedData.serverType 
      //   if (parsedData.name == element.name) {
      //     element.serverType = parsedData.serverType;
      //     element.msg = parsedData.msg;

      //   }
      // });

      clientList.forEach(function each(client) {
        if (client.socket.readyState === WebSocket.OPEN) {
          if (parsedData.serverType == 'odroid') {
              // Divide incoming data into multiple components
              var error = [];
              var Digestor =  digest(parsedData);

              // pack all the data to be sent to front-end.
              var encapsulator = encapsulate(Digestor, error);


            // clientList.forEach((elem) => {
              // if (elem.serverType == 'odroid') {
              //   elem.socket.send(data);
              // }
            // });
          }

          else {
            clientList.forEach((elem) => {
            
      //      

              // if (elem.serverType == 'dasboard') {
              //   elem.socket.send(JSON.stringify(Encapsulation));
              // }
            });
          }

        }
      });



    }

    // console.log(clientList);


    // var serverType = parsedData.serverType;
    // console.log(serverType);

    // wss.clients.forEach(function each(client) {
    //   if (client.readyState === WebSocket.OPEN) {
    //     client.send(data);
    //   }
    // });
  });
});