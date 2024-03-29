const digest = require("../Digester");
const encapsulate = require("../Encapsulate");

//Return a mock object for the data that needs to be handled on the front-end

function mock() {
	const newData = {
		speed: [
			{
				name: "speed",
				value: 25 * Math.random(),
			},
		],
		temperatures: [
			{
				name: "motor",
				value: 55 * Math.random() + 20,
			},
			{ name: "battery", value: 55 * Math.random() + 20},
		],
		position: [100 * Math.random(), 46],
		brakes: [
			{
				name: "brakes_left",
				status: 0,
				value: 3 * Math.random(),
			},
			{
				name: "brakes_right",
				status: 0,
				value: 3 * Math.random(),
			},
		],
		battery: [
			{
				name: "battery_1",
				value: 100 * Math.random(),
			},
			{
				name: "battery_2",
				value: 100 * Math.random(),
			},
		],
	};

	const Digest = digest(newData);
	const Encapsulate = encapsulate(Digest);
	return Encapsulate;
}

module.exports = mock;
