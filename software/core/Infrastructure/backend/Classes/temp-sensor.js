const Sensor = require("./sensor");

class TempSensor extends Sensor {
	sensor_type = "TEMPERATURE";
	constructor(name, value) {
		super(name, value);
	}
}

// const sensor1 = new TempSensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = TempSensor;
