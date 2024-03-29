//Which ever sensor inherited from this class should make use of the value property when possible
//avoid unit-specific property such as pressure - this makes it harder on the front-end to parse

class Sensor {
	sensor_type = "";
	constructor(name, value = null) {
		this._name = name;
		this._value = value;
	}

	get name() {
		return this._name;
	}

	get value() {
		return this._value;
	}

	set name(newName) {
		this._name = newName;
	}

	set value(newValue) {
		this._value = newValue;
	}

	get sensor_type() {
		return this.sensor_type;
	}
}

// const sensor1 = new Sensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = Sensor;
