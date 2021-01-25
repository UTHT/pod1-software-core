const Sensor = require("./sensor");

class BrakeSensor extends Sensor {
	sensor_type = "BRAKE";
	constructor(value, name = "brakes") {
		super(name, value);
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
