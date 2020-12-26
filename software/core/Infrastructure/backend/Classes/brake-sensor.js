const Sensor = require("./sensor");

class BrakeSensor extends Sensor {
	sensor_type = "BRAKE";
	constructor(value,  pressure = 0,name = "brakes") {
		super(name, value);
		this._name = name;
		this._pressure = pressure;
	}

}

// const sensor1 = new BatterySensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = BrakeSensor;
