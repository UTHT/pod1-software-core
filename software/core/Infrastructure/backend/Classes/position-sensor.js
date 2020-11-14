const Sensor = require("./sensor");

class PositionSensor extends Sensor {
	constructor(x, y, name = "position") {
		super(name);
		this._x = x;
		this._y = y;
		this._name = name;
	}

	set x(value) {
		this._x = value;
	}

	set y(value) {
		this._y = value;
	}
	get x() {
		return this._x;
	}

	get y() {
		return this._y;
	}

	get coordinates() {
		return [this._x, this._y];
	}
}

// const sensor1 = new PositionSensor("mysensor", 2, 3.21, 4.66);

// console.log(sensor1.name);
// console.log(sensor1.value);
// console.log(sensor1.x);
// console.log(sensor1.y);
// console.log(sensor1.coordinates);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;
// sensor1.x = 3.6;
// sensor1.y = 4.6;

// console.log(sensor1.name);
// console.log(sensor1.value);
// console.log(sensor1.x);
// console.log(sensor1.y);
// console.log(sensor1.coordinates);

module.exports = PositionSensor;
