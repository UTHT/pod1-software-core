const fs = require("fs");

// var commonErrors = fs.readFileSync("./commonErrors.json");
// var commonErrorsParsed = JSON.parse(commonErrors);
// var commonErrorkeyArray = Object.keys(commonErrorsParsed);

const validate = require("../validator/validate");

var global_data = {};
var temp_dict = {
    "name": "empty",
    "value": "-1"
};

/**
 * Inputs placeholders values for absent sensors in the orignal JSON odroid data
 *
 * @param {[Object object] <JSON>} json_odriod_data
 * @param {[Object]} error_array
* @returns {Object}
 */
function corrector(json_odriod_data, error_array) {

    global_data = json_odriod_data;

    error_array.forEach(element => {
      error_type = element.error;
      switch (true) {
        case error_type == "speedNotFoundError":
          insert_name_value("speed");
          break;
        case error_type == "temperatureNotFoundError":
          insert_name_value("temperatures");
          break;
        case error_type == "brakesNotFoundError":
          insert_brakes();
          break;
        case error_type == "batteryNotFoundError":
          insert_name_value("battery");
          break;
        case error_type == "currentNotFoundError":
          insert_name_value("current");
          break;
        case error_type == "vibrationNotFoundError":
          insert_name_value("vibration");
          break;
        case error_type == "gapHeightNotFoundError":
          insert_name_value("gapHeight");
          break;
        case error_type == "accelerationNotFoundError":
          insert_name_value("acceleration");
          break;
        default:
          break;
      }
    });

    return global_data;
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

-------------------------------Testing Data-------------------------------------------
*/


var test_data = fs.readFileSync("./test_data.json");
var  validator_error_array = validate(JSON.parse(test_data));
// console.log(validator_error_array);

const correct_object = corrector(JSON.parse(test_data), validator_error_array)
console.log(JSON.stringify(correct_object, null, 4));

module.exports = corrector;