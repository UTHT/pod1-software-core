const Sensor = require("./sensor");

class StateMachineSensor extends Sensor {
	sensor_type = "StateMachineSensor";
	constructor(value, name = "state") {
		super(name, value);
		this._name = name;
	}
}

// const sensor1 = new BatterySensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = StateMachineSensor;