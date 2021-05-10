const fs = require("fs");

// var commonErrors = fs.readFileSync("./commonErrors.json");
// var commonErrorsParsed = JSON.parse(commonErrors);
// var commonErrorkeyArray = Object.keys(commonErrorsParsed);

var global_data = {};
var temp_dict = {
    "name": "empty",
    "value": "-1"
};

function corrector(json_odriod_data, error_array) {

    global_data = json_odriod_data;

    error_array.forEach(element => {
        if (element.error == "speedNotFoundError") insert_name_value("speed");
        if (element.error == "temperatureNotFoundError") insert_name_value("temperatures");
        if (element.error == "brakesNotFoundError") insert_brakes();
        if (element.error == "batteryNotFoundError") insert_name_value("battery");
        if (element.error == "currentNotFoundError") insert_name_value("current");
        if (element.error == "vibrationNotFoundError") insert_name_value("vibration");
        if (element.error == "gapHeightNotFoundError") insert_name_value("gapHeight");
        if (element.error == "accelerationNotFoundError") insert_name_value("acceleration");
    });

    return global_data;
    // console.log(JSON.stringify(global_data, null, 4));
}

function insert_name_value(sensor_name){
    global_data[sensor_name] = [];
    global_data[sensor_name].push(temp_dict);
}

function insert_brakes() {
    global_data["brakes"] = [];
    var temp_brake_dict = {
        "name": "empty",
        "status": "-1",
        "pressure": "-1"    
    }

    global_data["brakes"] = temp_brake_dict;
}

/*
--------------------------------Testing Data-----------------------------------------
*/

var error_array =
[
    {
      errorId: 1,
      dataArrayName: 'speedDataArray',
      entity: 'speed',
      error: 'speedNotFoundError'
    },
    {
      errorId: 2,
      dataArrayName: 'temperatureDataArray',
      entity: 'temperatures',
      thresholdValue: 1000,
      error: 'temperatureNotFoundError'
    },
    {
      errorId: 3,
      dataArrayName: 'brakeDataArray',
      entity: 'brakes',
      thresholdValue: 200,
      error: 'brakesNotFoundError'
    },
    {
      errorId: 4,
      dataArrayName: 'batteryDataArray',
      entity: 'battery',
      thresholdValue: 100,
      error: 'batteryNotFoundError'
    },
    {
      errorId: 5,
      dataArrayName: 'currentDataArray',
      entity: 'current',
      thresholdValue: 100,
      error: 'currentNotFoundError'
    },
    {
      errorId: 6,
      dataArrayName: 'currentDataArray',
      entity: 'vibration',
      thresholdValue: 100,
      error: 'vibrationNotFoundError'
    },
    {
      errorId: 7,
      dataArrayName: 'gapHeightDataArray',
      entity: 'gapHeight',
      thresholdValue: 100,
      error: 'gapHeightNotFoundError'
    },
    {
      errorId: 8,
      dataArrayName: 'accelerationDataArray',
      entity: 'acceleration',
      error: 'accelerationNotFoundError'
    }
  ]

error_array.forEach(elem => {
    // console.log(elem.error);
});


/*
-------------------------------Testing Data-------------------------------------------
*/



var test_data = fs.readFileSync("./test_data.json");
// var test_errors = fs.readFileSync("./test_error.json");

// var  error_obj = validate(JSON.parse(test_data));
const correct_object = corrector(JSON.parse(test_data), error_array)
console.log(JSON.stringify(correct_object, null, 4));

module.exports = corrector;