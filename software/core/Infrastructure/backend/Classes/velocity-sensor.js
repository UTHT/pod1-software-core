const Sensor = require("./sensor");

class SpeedSensor extends Sensor {
	sensor_type = "VELOCITY";

	constructor(value, name = "velocity") {
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

module.exports = VelocitySensor;
