const Sensor = require("./sensor");

class BatterySensor extends Sensor {
	constructor(value, name = "battery") {
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

module.exports = BatterySensor;
