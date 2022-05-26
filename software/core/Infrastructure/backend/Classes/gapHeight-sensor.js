const Sensor = require("./sensor");

class GapHeightSensor extends Sensor {
	sensor_type = "GAPHEIGHT";
	constructor(value, name = "gapHeight") {
		super(name, value);
		this._name = name;
	}
}

module.exports = GapHeightSensor;