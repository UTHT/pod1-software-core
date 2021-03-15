const Sensor = require("./sensor");

class SpeedSensor extends Sensor {
	sensor_type = "SPEED";

	constructor(value, name = "speed") {
		super(name, value);
		this._name = name;
	}
}

// const sensor1 = new SpeedSensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = SpeedSensor;
