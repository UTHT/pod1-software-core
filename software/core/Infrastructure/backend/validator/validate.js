/*
speed:
- more than 0 and less than some threshold
- only double type

temp:
- more than 0 less than some threshold
- only double type

battery:
- more than 0 and less than 100%
- double type or integer type

brake pressure:
- more than 0 and less than some threshold
- only double type
- status:
    - only 0 or 1 (failed or working)
    - only integer type

location: 
- more than 0 and less than some threshold
- only double type

*/

const { throws } = require("assert");
const fs = require("fs");
const ValidationError = require('./ValidationErrorClass')


/**
 * Validate incoming JSON data for structural and syntactical integrity
 * returns array of errors for each respective data in jsonOdroidData
 * @param {[Object object] <JSON>} jsonOdriodData 
 * @returns {... List<Class>} [errors]
 */
function validate(jsonOdriodData){
    var errorarray = [];

    //structural integrity of data:
        //sensor type
        //has name and value

    //call appropriate sensor functions for it respective fields as the sensor type is detected in the for loop

    //loop through json data
        //when sensor type detected call appropriate sensor funtion 
            //if name detected
                //if it does not have string throw syntax error and populate error array
                //else push to data base 
            //if value detected
                //if value does not have double/integer throw syntax error and populate error array
                //else value not detected throw value error and populate error array
        //if no type detected throw type error and populate error array
        
        if ('speed' in jsonOdriodData){
            errorarray.push(checkSpeedData(jsonOdriodData.speed));
            // checkSpeedData(jsonOdriodData.speed);
            // console.log(errorarray);
        }
        else{
            //throw speed type error
            errorarray.push(new ValidationError('No field: speed').message);
            // console.log(errorarray);
        }

        if ('temperatures' in jsonOdriodData){
            errorarray.push(checkTempData(jsonOdriodData.temperatures));
            // checkTempData(jsonOdriodData.temperatures);
            // console.log(errorarray);
        }
        else{
            //throw temprature type error
            errorarray.push(new ValidationError('No field: temperatures').message);
            // console.log(errorarray);
        }

        if ('position' in jsonOdriodData){
            errorarray.push(checkPositionData(jsonOdriodData.position));
            // consol.log(checkPositionData(jsonOdriodData.position));
            console.log(errorarray);
        }
        else{
            //throw position type error
            errorarray.push(new ValidationError('No field: position').message);
        }

        // if ('brakes' in jsonOdriodData){
        //     errorarray.push(checkBrakeData(jsonOdriodData.brakes));

        // }
        // else{
        //     //throw brakes type error
        // }

        // if ('battery' in jsonOdriodData){
        //     errorarray.push(checkBatteryData(jsonOdriodData.battery));

        // }
        // else{
        //     //throw battery type error
        // }

    //generate and return error array
///dont return/send the error data further


    //call fuctions to check if less than threshold value 
    //call respective component's class to check if type is valid
        //any other fields that are specific to that component
        //is checked in that class

    
/* SKIP FOR NOW
send ALL data to database (regardless of it being correct or incorrect)
set flags in database that indicate correct and incorrect data
integrer flag: 0 for bad and 1 for good
*/


}


//function: validate speed value
function checkSpeedData(speedDataArray) {
    if ('value' in speedDataArray){
        console.log("speed value exists");

        //check if value is more than 0
        if (speedDataArray.value > 0){ 
            console.log("speed value exists");            
        }
        else {
            return new ValidationError('Speed cannot be less than 0').message;
        }
    }
    else {
        return new ValidationError('No field: value');
    }
}

//function: validate temp name
//function: validate temp value
function checkTempData(temperatureArrayData){
    var temperatureErrors = {}


    temperatureArrayData.forEach((element, index) => {
        if ('name' in element){
            // console.log(element.name);
        }
        else{
            temperatureErrors[index] = new ValidationError("No field: name").message;
        }

        if ('value' in element){
            // console.log(element.value);
        }
        else{
            temperatureErrors[index] = new ValidationError("No field: value").message;
        }
    });

    return temperatureErrors;
}


//function: validate position value
//function: validate brake name
function checkPositionData(positionArrayData){
    var positionErrors = {}

    positionArrayData.forEach((elem, index) => {
        if (elem > 0){
            // console.log(elem);
        }
        else if (elem < 0){
            positionErrors[index] = new ValidationError("Position cannot be less than 0").message;
        }
        else{
            positionErrors[index] = new ValidationError("No values provided for position").message;
        }
    });

    return positionErrors;
}

//function: validate brake status
//function: validate brake value
//function: validate battery name
//function: validate battery value
//function: validate podstate ???
//function: validate timeStamp ???



var tempdata = fs.readFileSync("./test.json");
const validateobject = validate(JSON.parse(tempdata));
// console.log(validateobject);

module.exports = validate;
