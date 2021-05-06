const { Socket } = require("dgram");
const WebSocket = require("ws");

const JSONParser = require("./externalSocketParser/parser");
const digest = require("./Digester/index");
const encapsulate = require("./Encapsulate/index");
const broadcast = require("./utilities/broadcast");
const mock = require("./utilities/mock");
const validate = require("./validator/validate");
const corrector = require("./dataCorrector/corrector");

const wss = new WebSocket.Server({ port: 8080 });

//websocket connection
wss.on("connection", function connection(ws) {
	//websocket message
	ws.on("message", function incoming(message) {
		// parsed incoming data from sockets
		// enforcing sending evenType with every message for easier data manipulation
		const { eventType, data } = JSONParser(message);
		console.log(data, message)

		//switch case is is better for in the future when there are more than 3 eventTypes
		switch (eventType) {
			// if the socket is just connected, tag it with the clientType property to be identifiable later
			// any clients should send this event during initialization of the ws connection
			case "connection":
				//Data should have a clientType to be added to the connection
				//Todo: maybe add an error event id clienType is undefined
				const clientType = data.clientType;
				ws.clientType = clientType;
				ws.send(JSON.stringify({ eventType: "init" }));
				return;

			// replay is any messages that just need to be passed to the clientType
			case "relay":
				if (ws.clientType === "dashboard") {
					//Todo: add encapsulation for the massage to go to the odroid
					broadcast(wss, message, "odroid");
				} else {
					var errorObj = {};

					// validate incoming data from the pod
					var errorObj = validate(data);
		
					// corrected json data
					var correctedData;
					correctedData = corrector(data, errorObj);

					// Divide incoming data into multiple components
					const Digestor = digest(correctedData);
					
					// pack all the data to be sent to front-end.
					const encapsulator = encapsulate(Digestor, errorObj);
					broadcast(wss, encapsulator, "dashboard");
				}
				return;

			// use to request for mock data to test the front-end components
			case "mock_request":
				const msg = { eventType: "mock", data: mock() };
				broadcast(wss, msg, "dashboard");
				return;

			//If eventType is not given or any of the above case then send an error message
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
