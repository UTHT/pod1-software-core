const Sensor = require("./sensor");

class VibrationSensor extends Sensor {
	sensor_type = "VIBRATION";
	constructor(value, name = "vibration") {
		super(name, value);
		this._name = name;
	}
}

module.exports = VibrationSensor;