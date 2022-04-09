const WebSocket = require("ws");

//A function to send messages to a specific clientType initialized into the ws object during the connection event
function broadcast(wss, data, clientType) {
	wss.clients.forEach((client) => {
		if (
			client.readyState === WebSocket.OPEN &&
			client.clientType === clientType
		) {
			client.send(JSON.stringify(data));
		}
	});
}

module.exports = broadcast;
