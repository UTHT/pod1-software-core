const Sensor = require("./sensor");

class AccelerationSensor extends Sensor {
	sensor_type = "ACCELERATION";
	constructor(value, name = "acceleration") {
		super(name, value);
		this._name = name;
	}
}

module.exports = AccelerationSensor;