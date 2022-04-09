const Sensor = require("./sensor");

class DCcurrentSensor extends Sensor {
	sensor_type = "DC_CURRENT";
	constructor(value, name = "dc_current") {
		super(name, value);
		this._name = name;
	}
}

module.exports = DCcurrentSensor;