const fs = require("fs");

var commonErrors = fs.readFileSync("./commonErrors.json");
var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsParsed);

function corrector(json_odriod_data, error_obj) {


}


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

console.log(JSON.stringify(obj, null, 4));

var test_data = fs.readFileSync("./test_data.json");
var test_errors = fs.readFileSync("./test_error.json");
// var  error_obj = validate(JSON.parse(test_data));
const correct_object = corrector(JSON.parse(test_data), JSON.parse(test_errors))
// console.log(correct_object);

module.exports = corrector;

