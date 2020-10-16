const WebSocket = require("ws");
const heartbeats = require("heartbeats");

const wss = new WebSocket.Server({ port: 8080 });

wss.on("connection", function connection(ws) {
	ws.on("message", function incoming(data) {
		const newData = JSON.parse(data);
		switch (newData.eventName) {
			case "broadcast":
				wss.clients.forEach(function each(client) {
					if (client.readyState === WebSocket.OPEN) {
						client.send(data);
					}
				});
			case "toggleStream":
				if (heartbeats.hearts.dataStream != undefined) {
					heartbeats.killHeart("dataStream");
				} else {
					const heart = heartbeats.createHeart(1000, "dataStream");
					heart.createEvent(1, (count, last) => {
						wss.clients.forEach(function each(client) {
							if (client.readyState === WebSocket.OPEN) {
								client.send(
									JSON.stringify({
										eventName: "mockData",
										message: { time: Date.now(), value: Math.random() * 20 },
									})
								);
							}
						});
					});
				}

			default:
				return null;
		}
	});
});
