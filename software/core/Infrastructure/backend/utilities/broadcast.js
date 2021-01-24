const WebSocket = require("ws");

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
