const { Socket } = require("dgram");
const WebSocket = require("ws");

const JSONParser = require("./externalSocketParser/parser");
const digest = require("./Digester/index");
const encapsulate = require("./Encapsulate/index");
const broadcast = require("./utilities/broadcast");
const mock = require("./utilities/mock");

const wss = new WebSocket.Server({ port: 8080 });
var clientList = [];

//websocket connection
wss.on("connection", function connection(ws) {
	//websocket message
	ws.on("message", function incoming(message) {
		// parsed incoming data from sockets
		const { eventType, data } = JSONParser(message);

		// if the socket is just connected, add it to the client list
		switch (eventType) {
			case "connection":
				const clientType = data.clientType;
				ws.clientType = clientType;
				ws.send(JSON.stringify({ eventType: "init" }));
			case "relay":
				if (ws.clientType === "dashboard") {
					broadcast(wss, message, "odroid");
				} else {
					const error = [];
					// validation module -- here

					// Divide incoming data into multiple components
					const Digestor = digest(parsedData);
					// pack all the data to be sent to front-end.
					const encapsulator = encapsulate(Digestor, error);
					broadcast(wss, encapsulator, "dashboard");
				}
			case "mock_request":
				const msg = { eventType: "mock", data: mock() };
				broadcast(wss, msg, "dashboard");
				return;
			default:
				ws.send(
					JSON.stringify({
						eventType: "error",
						data: { message: "No event of that type found" },
					})
				);
		}
	});
});
