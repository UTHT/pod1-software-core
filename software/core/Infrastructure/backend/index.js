const WebSocket = require("ws");
const heartbeats = require("heartbeats");
const heart = heartbeats.createHeart(1000);

const wss = new WebSocket.Server({ port: 8080 });

wss.on("connection", function connection(ws) {
	ws.on("message", function incoming(data) {
		wss.clients.forEach(function each(client) {
			if (client.readyState === WebSocket.OPEN) {
				client.send(data);
			}
		});
	});

	heart.createEvent(1, (count, last) => {
		wss.clients.forEach(function each(client) {
			if (client.readyState === WebSocket.OPEN) {
				client.send(JSON.stringify({ message: "hello" }));
			}
		});
	});
});
