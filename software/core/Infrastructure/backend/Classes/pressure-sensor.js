const Sensor = require("./sensor");

class PressureSensor extends Sensor {
	sensor_type = "PRESSURE";

	constructor(value, name = "pressure") {
		super(name, value);
		this._name = name;
	}
}

module.exports = PressureSensor;
