const { Socket } = require('dgram');
const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });
var clientList = [];

//websocket connection
wss.on('connection', function connection(ws) {
  //websocket message
  ws.on('message', function incoming(data) {

    parsedData = JSON.parse(data);

    if (parsedData.isNew) {
      parsedData["socket"] = ws;
      clientList.push(parsedData);
    }
    else {

      clientList.forEach((element) => {
        //if unique ID match, changee element.serverType to parsedData.serverType 
        if (parsedData.name == element.name) {
          element.serverType = parsedData.serverType;
          element.msg = parsedData.msg;

        }
      });

      clientList.forEach(function each(client) {
        if (client.socket.readyState === WebSocket.OPEN) {
          if (parsedData.serverType == 'A') {
            clientList.forEach((elem) => {
              if (elem.serverType == 'B') {
                elem.socket.send(data);
              }
            });
          }

          else {
            clientList.forEach((elem) => {
              if (elem.serverType == 'A') {
                elem.socket.send(data);
              }
            });
          }

        }
      });

    }

    console.log(clientList);


    // var serverType = parsedData.serverType;
    // console.log(serverType);

    // wss.clients.forEach(function each(client) {
    //   if (client.readyState === WebSocket.OPEN) {
    //     client.send(data);
    //   }
    // });
  });
});