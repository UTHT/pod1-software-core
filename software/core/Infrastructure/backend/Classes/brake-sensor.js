const Sensor = require("./sensor");

class BrakeSensor extends Sensor {
	sensor_type = "BRAKE";
	constructor(pressure, name = "brakes") {
		super(name, pressure);
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
