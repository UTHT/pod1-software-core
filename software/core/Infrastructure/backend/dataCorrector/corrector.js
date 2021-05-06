const fs = require("fs");

function corrector(json_odriod_data, error_obj) {

}


var test_data = fs.readFileSync("./test_data.json");
var test_errors = fs.readFileSync("./test_error.json");
const correct_object = validate(JSON.parse(test_data), JSON.parse(test_errors));
console.log(correct_object);

module.exports = corrector;
