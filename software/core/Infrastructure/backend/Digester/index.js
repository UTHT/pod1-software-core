const BatterySensor = require("../Classes/battery-sensor");
const PositionSensor = require("../Classes/position-sensor");
const SpeedSensor = require("../Classes/speed-sensor");
const TempSensor = require("../Classes/temp-sensor");
const BrakeSensor = require("../Classes/brake-sensor");

const fs = require("fs");

/**
 * Breakdown incoming data into corresponding classes.
 * Digestor works as a middle man to ensure data integerity and structure.
 * @param {[Object object] <JSON>} odroid_json
 * @returns {... List<Class>} [Speed, Battery, Position, ...temp_array, Brakes]
 */
function digest(odroid_json) {
	const { speed, temperatures, battery, position, brakes } = odroid_json;

	const Speed = speed.map(({ name, value }) => new SpeedSensor(value, name));

	const Battery = battery.map(
		({ name, value }) => new BatterySensor(value, name)
	);

	const Position = new PositionSensor(position[0], position[1]);

	const temp_array = temperatures.map(
		({ name, value }) => new TempSensor(value, name)
	);

	const Brakes = brakes.map(({ name, value }) => new BrakeSensor(value, name));

	return [...Speed, ...Battery, Position, ...temp_array, ...Brakes];
}

// const data = fs.readFileSync("./test.json");

// const digester_object = digest(JSON.parse(data));
// console.log(digester_object);

module.exports = digest;
