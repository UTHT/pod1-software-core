class Sensor {
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
}

// const sensor1 = new Sensor("mysensor", 2);

// console.log(sensor1.name);
// console.log(sensor1.value);

// sensor1.name = "updatedsensor";
// sensor1.value = 3;

// console.log(sensor1.name);
// console.log(sensor1.value);

module.exports = Sensor;
