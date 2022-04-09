//parsedData (from ./index.js is passed into validate.js)

const Validator = require('validatorjs');
const fs = require("fs");

//validate data according to appripriate rules
//data correctness and structural integrity

let data = fs.readFileSync("./test.json");

let rules = {
    timeStamp: {
        name: 'required|string',
        lastActiveDate: 'required|date',
    },
    speed: {
        // name: 'required|string',
        value: 'required|min:0'
    },
    temp: [{
        name: 'required|string',
        value: 'required|min:0'
    }],
    batterylevel: [{
        name: 'required|string',
        value: 'required|min:0'
    }],
    brakepressure: [{
        name: 'required|string',
        value: 'required|min:0'
    }],
    podstate: {
        debug: 'required|integer',
        off: 'required|integer',
        commmscheck: 'required|integer',
        systemcheck: 'required|integer',
        lock: 'required|integer',
        arm: 'required|integer',
        shutdown: 'required|integer',
        braking: 'required|integer',
        estop: 'required|integer',
        drive: 'required|integer',

    },
    location: 'required|array'

};

let validation = new Validator(data, rules,
     {"required.location": "Without an :attribute we can't reach you!"});

// console.log(validation.passes());
//console.log(validation.rules.speed);
// console.log(Object.keys(validation.errors));
// console.log(Object.values(validation.errors));


/**
* validate parsed json data from odroid
* @param {List<Object>} jsondata 
* @returns {List<String>} {error: error}
*/
function validate(jsondata) {


    //return error messages as a list 
    var errorarray = [];
    // for (const elem of validation.errors) {
    //     errorarray.push(elem);
    // }

    // errors = validation.errors.all();
    // return errorarray;



/*send ALL data to database (regardless of it being correct or incorrect)
set flags in database that indicate correct and incorrect data
integrer flag: 0 for bad and 1 for good
*/

// console.log(validation.passes());


}

// console.log(data);
// const validate_object = validate((data))
// console.log(validate_object);

module.exports = validate;
