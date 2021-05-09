const fs = require("fs");

// var commonErrors = fs.readFileSync("./commonErrors.json");
// var commonErrorsParsed = JSON.parse(commonErrors);
// var commonErrorkeyArray = Object.keys(commonErrorsParsed);

function corrector(json_odriod_data, error_array) {



    // for (const [dataArray, sensor] of Object.entries(error_obj)) {
    //     for (const [sensor_key, error] of Object.entries(sensor)){
    //         for (const [error_key, value] of Object.entries(error)){
    //             // console.log(error_key)
    //             // if (error_key == "speedNotFoundError") insert_speed();

    //         }
    //     }
    // }

}

var error_array =
[
    {
      errorId: 1,
      dataArrayName: 'speedDataArray',
      entity: 1,
      error: 'negativeValueError'
    },
    {
      errorId: 2,
      dataArrayName: 'speedDataArray',
      entity: 1,
      error: 'nameNotFoundError'
    },
    {
      errorId: 3,
      dataArrayName: 'temperatureDataArray',
      entity: 1,
      thresholdValue: 1000,
      error: 'nameNotFoundError'
    }
]

error_array.forEach(elem => {
    // console.log(elem.error);
});

/*
------------------------------------------------------
*/

var temp_error = {
    "brakeDataArray": {
        "brakes": {
            "nameNotFoundError": [
                {
                    "errorId": 6,
                    "entity": 1,
                    "thresholdValue": 100,
                    "error": "nameNotFoundError"
                }
            ]
        }
    } 
};

// if (temp_error.brakeDataArray.brakes.brakesNotFoundError) console.log("true");
// else console.log("false"); 

/*
------------------------------------------------------------
*/

var obj = {
    "speed": [
        {
            "value": -8
        }
    ],
};

var temp_dict = {"name": "speed", "value": 0};
obj["speed"][0] = temp_dict;

var temp_string = "temp";
var hello = "hello";
obj["speed"][0][temp_string] = hello;

// console.log(JSON.stringify(obj, null, 4));







var test_data = fs.readFileSync("./test_data.json");
var test_errors = fs.readFileSync("./test_error.json");

// var  error_obj = validate(JSON.parse(test_data));
const correct_object = corrector(JSON.parse(test_data), JSON.parse(test_errors))
// console.log(correct_object);

module.exports = corrector;