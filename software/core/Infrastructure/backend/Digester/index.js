const BatterySensor = require("../Classes/battery-sensor");
const PositionSensor = require("../Classes/position-sensor");
const SpeedSensor = require("../Classes/speed-sensor");
const TempSensor = require("../Classes/temp-sensor");

const fs = require("fs");

function digest(odroid_json) {
	const odroid_object = JSON.parse(odroid_json);

	const { speed, temperatures, battery, position } = odroid_object;

	const Speed = new SpeedSensor(speed);
	const Battery = new BatterySensor(battery);
	const Position = new PositionSensor(position[0], position[1]);
	const temp_array = temperatures.map(
		({ name, value }) => new TempSensor(name, value)
	);

	return [Speed, Battery, Position, ...temp_array];
}

//testing
// const data = fs.readFileSync("test.json");

// const digester_object = digest(data);
// console.log(digester_object);

module.exports = {
	digest,
};
