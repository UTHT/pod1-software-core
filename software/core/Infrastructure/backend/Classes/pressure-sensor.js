const Sensor = require("./sensor");

class PressureSensor extends Sensor {
	sensor_type = "PRESSURE";

	constructor(value, name = "pressure") {
		super(name, value);
		this._name = name;
	}
}

// const sensor1 = new BrakeSensor(0,254);

// console.log(sensor1.name);
// console.log(sensor1.value);
// console.log(sensor1.pressure);

// sensor1.name = "updatedsensor";
// sensor1.value = 1;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = BrakeSensor;
