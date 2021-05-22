const Sensor = require("./sensor");

class CurrentSensor extends Sensor {
	sensor_type = "CURRENT";
	constructor(value, name = "current") {
		super(name, value);
		this._name = name;
	}
}

module.exports = CurrentSensor;