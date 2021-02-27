const { Console } = require("console");
const fs = require("fs");
const ValidationError = require('./ValidationErrorClass')

var commonErrors = fs.readFileSync("./commonErrors.json");
var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsParsed);


/**
 * Validate incoming JSON data for structural and syntactical integrity
 * returns array of errors for each sensor type in jsonOdroidData
 * @param {[Object object] <JSON>} jsonOdriodData 
 * @returns {... List<Class>} [errors]
 */
function validate(jsonOdriodData) {

    //structural integrity of data:
    //sensor type
    //has name and value

    //call appropriate sensor functions for it respective fields as the sensor type is detected

    //loop through json data
    //when sensor type detected call appropriate sensor funtion 
    //if name detected
    //if it does not have string throw syntax error and populate error array
    //else push to data base 
    //if value detected
    //if value does not have double/integer throw syntax error and populate error array
    //else value not detected throw value error and populate error array
    //if no type detected throw type error and populate error array


    var errorarray = []

    error_id = 0;
    var speedDataDict = {
        errorId: error_id,
        dataArrayName: 'speedDataArray',
        field: '',
        error: ''
    }
    var temperatureDataDict = {
        errorId: error_id,
        dataArrayName: 'temperatureDataArray',
        field: '',
        error: ''
    }

    // test.push(speedDataDict);
    // console.log(test);

    if ('speed' in jsonOdriodData) {
        errorarray.push(checkSpeedData(jsonOdriodData.speed, speedDataDict));
        console.log(errorarray);
    }
    else {
        //throw speed type error
        errorarray.push(sensorTypeError('speed', speedDataDict));
        console.log(errorarray);
    }

    if ('temperatures' in jsonOdriodData) {
        // errorarray.push(checkTempData(jsonOdriodData.temperatures));
        // tempArray = [];
        // checkTempData(jsonOdriodData.temperatures, temperatureDataDict, error_id);
        // tempArray = checkTempData(jsonOdriodData.temperatures, temperatureDataDict, error_id);
        // tempArray.forEach(elem => {
        //     errorarray.push(elem);
        // })
        // console.log(errorarray);
    }
    else {
        //throw temprature type error
        errorarray.push(sensorTypeError('temperature', temperatureDataDict));
        console.log(errorarray);
    }

    if ('position' in jsonOdriodData) {
        // errorarray.push(checkPositionData(jsonOdriodData.position));
        // consol.log(checkPositionData(jsonOdriodData.position));
        // console.log(errorarray);
    }
    else {
        //throw position type error
        // errorarray.push(new ValidationError('No field: position').message);
    }

    if ('brakes' in jsonOdriodData) {
        // errorarray.push(checkBrakeData(jsonOdriodData.brakes));
        // console.log(checkBrakeData(jsonOdriodData.brakes));
        // console.log(errorarray);
    }
    else {
        //throw brakes type error
        // errorarray.push(new ValidationError('No field: brakes').message);
        // console.log(errorarray);
    }

    if ('battery' in jsonOdriodData) {
        // errorarray.push(checkBatteryData(jsonOdriodData.battery));
        // console.log(checkBatteryData(jsonOdriodData.brakes));
        // console.log(errorarray);
    }
    else {
        //throw battery type error
        // errorarray.push(new ValidationError('No field: battery').message);
        // console.log(errorarray);

    }



    //generate and return error array
    ///dont return/send the error data further

    //the following two funciton convert the error array into an array with nested objects

    /**
 * Creates nested groups by object properties.
 * `properties` array nest from highest(index = 0) to lowest level.
 *
 * @param {String[]} properties
 * @returns {Object}
 */
    function nestGroupsBy(arr, properties) {
        properties = Array.from(properties);
        if (properties.length === 1) {
            return groupBy(arr, properties[0]);
        }
        const property = properties.shift();
        var grouped = groupBy(arr, property);
        for (let key in grouped) {
            grouped[key] = nestGroupsBy(grouped[key], Array.from(properties));
        }
        return grouped;
    }

    /**
     * Group objects by property.
     * `nestGroupsBy` helper method.
     *
     * @param {String} property
     * @param {Object[]} conversions
     * @returns {Object}
     */
    function groupBy(conversions, property) {
        return conversions.reduce((acc, obj) => {
            let key = obj[property];
            if (!acc[key]) {
                acc[key] = [];
            }
            acc[key].push(obj);
            return acc;
        }, {});
    }

    const groups = nestGroupsBy(errorarray, ['dataArrayName', 'field', 'error']);
    // console.log(JSON.stringify(groups, null, 2));

}

//increment error id
function incremenErrorId(error_id) {
    var temp = error_id + 1;
    return temp;
}

//FIX ERROR ID INCREMENT
//returns error for appropriate sensor that is not found in original json data
function sensorTypeError(sensorType, dataDict) {
    //speedNotFoundError
    if (sensorType == 'speed') {
        dataDict['errorId'] = incremenErrorId(dataDict['errorId']);
        dataDict['field'] = 'speed';
        dataDict['error'] = commonErrorkeyArray[6];
    }

    //temperatureNotFoundError
    if (sensorType == 'temperature') {
        dataDict['errorId'] = incremenErrorId(dataDict['errorId']);
        dataDict['field'] = 'temperature';
        dataDict['error'] = commonErrorkeyArray[7];
    }

    return dataDict
}


//validates speed value
function checkSpeedData(speedDataArray, speedDataDict) {
    speedDataArray.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                // var incrementedErrorId = incremenErrorId(error_id);
                speedDataDict['errorId'] = incremenErrorId(speedDataDict['errorId']);
                speedDataDict['field'] = 'value';
                speedDataDict['error'] = commonErrorkeyArray[0];
            }
        }
        else {
            //valueNotFoundError
            error_id += 1;
            speedDataDict['errorId'] = incremenErrorId(speedDataDict['errorId']);
            speedDataDict['field'] = 'value';
            speedDataDict['error'] = commonErrorkeyArray[2];
        }
    });

    return speedDataDict;
}

//validate temp name and value
//FIX ERROR ID INCREMENT
function checkTempData(temperatureArrayData, temperatureDataDict) {
    temperatureArray = [];

    temperatureArrayData.forEach(element => {
        // console.log(element);
        if ('name' in element) {
            // console.log(element.name);
        }
        else {
            //nameNotFoundError
            temperatureDataDict['errorId'] = incremenErrorId(temperatureDataDict['errorId']);
            temperatureDataDict['field'] = 'name';
            temperatureDataDict['error'] = commonErrorkeyArray[3];
        }

        // if ('value' in element) {
        //     //check if value is more than 0
        //     if (element.value < 0) {
        //         //negativeValueError
        //         temperatureDataDict['errorId'] = incremenErrorId(temperatureDataDict['errorId']);
        //         temperatureDataDict['field'] = 'value';
        //         temperatureDataDict['error'] = commonErrorkeyArray[0];
        //     }
        // }
        // else {
        //     //valueNotFoundError
        //     temperatureDataDict['errorId'] = incremenErrorId(temperatureDataDict['errorId']);
        //     temperatureDataDict['field'] = 'value';
        //     temperatureDataDict['error'] = commonErrorkeyArray[2];
        // }
        console.log("temperatureDataDict here: ");
        // console.log(temperatureDataDict);
        console.log("temperatureArray here: ")
        temperatureArray.push(temperatureDataDict);
        // console.log(temperatureArray)
        });


    // console.log(temperatureArray)
    // return temperatureArray;
}


//validate position value
function checkPositionData(positionArrayData) {
    var positionErrors = {}

    positionArrayData.forEach((elem, index) => {
        if (elem > 0) {
            // console.log(elem);
        }
        else if (elem < 0) {
            positionErrors[index] = new ValidationError("Position cannot be less than 0").message;
        }
        else {
            positionErrors[index] = new ValidationError("No values provided for position").message;
        }
    });

    return positionErrors;
}

//function: validate brake status
//function: validate brake value
function checkBrakeData(brakeArrayData) {
    var brakeErrors = {};

    brakeArrayData.forEach((element, index) => {
        for ([key, val] of Object.entries(element)) {
            if ('name' in element) {
                // console.log(element.name);
            }
            else {
                brakeErrors["name"] = new ValidationError("No field").message;
            }

            if ('status' in element) {
                // console.log(element.status);
            }
            else {
                brakeErrors["status"] = new ValidationError("No field").message;
            }

            if ('pressure' in element) {
                // console.log(element.pressure);
            }
            else {
                brakeErrors["pressure"] = new ValidationError("No field").message;
            }
        }

    });

    return brakeErrors;

}

//function: validate battery name and battery value
function checkBatteryData(batteryArrayData) {
    var batteryErrors = {};

    batteryArrayData.forEach((element, index) => {
        for ([key, val] of Object.entries(element)) {
            if ('name' in element) {
                // console.log(element.name);
            }
            else {
                batteryErrors["name"] = new ValidationError("No field").message;
            }

            if ('status' in element) {
                // console.log(element.status);
            }
            else {
                batteryErrors["value"] = new ValidationError("No field").message;
            }
        }

    });

    return batteryErrors;

}

//function: validate podstate ???
//function: validate timeStamp ???



var tempdata = fs.readFileSync("./test.json");
const validateobject = validate(JSON.parse(tempdata));
// console.log(validateobject);

module.exports = validate;


//random test code

// console.log(errorarray);
// console.log(JSON.stringify(errorarray, null, 2));

// console.log(commonErrorsParsed);
// let first  = commonErrorkeyArray[0];
// console.log(`the key is ${first}`);

// let soMany = commonErrors[0];
// console.log(`This is ${soMany} times easier!`);

// var test = [
//     {
//         speedDataArray: {
//             value: {
//                 "negativeValueError": "can not have a negative value"
//             }
//         }
//     }
// ]
// console.log(JSON.stringify(test, null, 2));

// var tempArray = [
//     {
//         errorId: '0',
//         dataArrayName: 'speedDataArray',
//         field: 'value',
//         error: 'valueNotFoundError'
//     },
//     {
//         errorId: '1',
//         dataArrayName: 'temperatureDataArray',
//         field: 'name',
//         error: 'nameNotFoundError'
//     }, {
//         errorId: '2',
//         dataArrayName: 'temperatureDataArray',
//         field: 'value',
//         error: 'negativeValueError'
//     }, {
//         errorId: '3',
//         dataArrayName: 'batteryDataArray',
//         field: 'value',
//         error: 'negativeValueError'
//     }, {
//         errorId: '4',
//         dataArrayName: 'batteryDataArray',
//         field: 'name',
//         error: 'nameNotFoundError'
//     },
// ]