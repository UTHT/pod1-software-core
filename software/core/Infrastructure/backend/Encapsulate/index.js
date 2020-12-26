const BatterySensor = require("../Classes/battery-sensor");
const PositionSensor = require("../Classes/position-sensor");
const SpeedSensor = require("../Classes/speed-sensor");
const TempSensor = require("../Classes/temp-sensor");

const fs = require("fs");

const { digest } = require("../Digester");

function encapsulate(digester_obj, error) {
	let obj = {};

	digester_obj.map((sensor) => {
		const type = sensor.sensor_type;
		//If the object don't already have a key with the type in it
		if (!obj.hasOwnProperty(type)) {
			obj = { ...obj, [type]: [sensor] };
		} else {
			const current_arr = obj[type];
			current_arr.push(sensor);
			obj = { ...obj, [type]: current_arr };
		}
	});

	return {obj, error: error};
}

//tests -> will write separate test file later
// const data = fs.readFileSync("test.json");

// console.log(data);
// const digester_object = digest(data);
// console.log(digester_object);

// const enc_obj = encapsulate(digester_object);
// console.log(enc_obj);

module.exports = encapsulate;
