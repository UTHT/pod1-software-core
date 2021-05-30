const BatterySensor = require("../Classes/battery-sensor");
const PositionSensor = require("../Classes/position-sensor");
const VelocitySensor = require("../Classes/velocity-sensor");
const TempSensor = require("../Classes/temp-sensor");
const PressureSensor = require("../Classes/pressure-sensor");
const AccelerationSensor = require("../Classes/acceleration-sensor");
const DCcurrentSensor = require("../Classes/dc_current-sensor");
const GapHeightSensor = require("../Classes/gapHeight-sensor");
const VibrationSensor = require("../Classes/vibration-sensor");

const validate = require("../validator/validate");
const corrector = require("../dataCorrector/corrector");

const fs = require("fs");

/**
 * Breakdown incoming data into corresponding classes.
 * Digestor works as a middle man to ensure data integerity and structure.
 * @param {[Object object] <JSON>} odroid_json
 * @returns {... List<Class>} [Velocity, Battery, Position, ...temp_array, Brakes, Acceleration,
 * Vibration, dcCurrent, GapHeight]
 */
function digest(odroid_json) {
	const { velocity, temperatures, battery, position, pressure, dcCurrent, vibration,
	 gapHeight, acceleration} = odroid_json;

	const Velocity = velocity.map(({ name, value }) => new VelocitySensor(value, name));

	const Battery = battery.map(
		({ name, value }) => new BatterySensor(value, name)
	);

	const Position = new PositionSensor(position[0], position[1]);

	const temp_array = temperatures.map(
		({ name, value }) => new TempSensor(name, value)
	);

	const Pressure = pressure.map(({ name, value }) => new PressureSensor(value, name,status,pressure));

	const Acceleration = acceleration.map(({ name, value }) => new AccelerationSensor(value, name));
	const DCcurrent = dcCurrent.map(({ name, value }) => new DCcurrentSensor(value, name));
	const GapHeight = gapHeight.map(({ name, value }) => new GapHeightSensor(value, name));
	const Vibration = vibration.map(({ name, value }) => new VibrationSensor(value, name));

	return [...Velocity, ...Battery, Position, ...temp_array, ...Pressure, ...Acceleration,
	...DCcurrent, ...GapHeight, ...Vibration];
}

const data = fs.readFileSync("./test.json");

var  validator_error_array = validate(JSON.parse(data));
// console.log(validator_error_array);

const correct_object = corrector(JSON.parse(data), validator_error_array)
console.log(JSON.stringify(correct_object, null, 4));

const digester_object = digest(JSON.parse(correct_object));
// console.log(digester_object);

module.exports = digest;

/*
Crash Report:
- when speed object completely removed
	- TypeError: Cannot read property 'map' of undefined
- when temperature object completely removed
	- TypeError: Cannot read property 'map' of undefined
- position completely removed	
	- TypeError: Cannot read property '0' of undefined
- when brakes object completely removed
	- TypeError: Cannot read property 'map' of undefined
- when battery object completely removed
	- TypeError: Cannot read property 'map' of undefined


Other notes:
- For brakes, not accounting for "status"
*/