const fs = require("fs");
const ValidationError = require('./ValidationErrorClass')

var commonErrors = fs.readFileSync("./commonErrors.json");
var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsParsed);


/**
 * Validate incoming JSON data for structural and syntactical integrity
 * returns array of errors for each respective data in jsonOdroidData
 * @param {[Object object] <JSON>} jsonOdriodData 
 * @returns {... List<Class>} [errors]
 */
function validate(jsonOdriodData) {

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

    //for example purposes only:

    var errorarray = [
        {
            errorId: '0',
            dataArrayName: 'speedDataArray',
            field: 'value',
            error: 'valueNotFoundError'
        },
        {
            errorId: '1',
            dataArrayName: 'temperatureDataArray',
            field: 'name',
            error: 'nameNotFoundError'
        }, {
            errorId: '2',
            dataArrayName: 'temperatureDataArray',
            field: 'value',
            error: 'negativeValueError'
        }, {
            errorId: '3',
            dataArrayName: 'batteryDataArray',
            field: 'value',
            error: 'negativeValueError'
        }, {
            errorId: '4',
            dataArrayName: 'batteryDataArray',
            field: 'name',
            error: 'nameNotFoundError'
        },
    ]

    // test.push(speedDataDict);
    // console.log(test);

    if ('speed' in jsonOdriodData) {
        // errorarray.push(checkSpeedData(jsonOdriodData.speed));
        // console.log(test);

        // errorarray.push(checkSpeedData(jsonOdriodData.speed));
        // checkSpeedData(jsonOdriodData.speed);
        // console.log(errorarray);
    }
    else {
        //throw speed type error
        // errorarray.push(new ValidationError('No field: speed').message);
        // console.log(errorarray);
    }

    if ('temperatures' in jsonOdriodData) {
        // errorarray.push(checkTempData(jsonOdriodData.temperatures));
        // checkTempData(jsonOdriodData.temperatures);
        // console.log(errorarray);
    }
    else {
        //throw temprature type error
        // errorarray.push(new ValidationError('No field: temperatures').message);
        // console.log(errorarray);
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
    console.log(JSON.stringify(groups, null, 2));

}

//IF NO FUNCTIONS RETURN ERROR --> NEED TO FIX UNDEFINED IN ERRORARRAY

//validates speed value
function checkSpeedData(speedDataArray) {
    var speedDataDict = {
        errorId: '0',
        dataArrayName: 'speedDataArray',
        field: '',
        error: ''
    }

    // var speedErrors = {}


    speedDataArray.forEach((elem, index) => {
        if ('value' in elem) {
            // console.log("speed value exists");

            //check if value is more than 0
            if (elem.value > 0) {
                // console.log("speed value more than 0: ", elem.value);
            }
            else {
                speedDataDict['errorId'] = parseInt(speedDataDict['errorId']) + 1;
                speedDataDict['field'] = 'value';
                speedDataDict['error'] = commonErrorkeyArray[0];
                // speedErrors[index] = new ValidationError('Speed cannot be less than 0').message;
            }
        }
        else {
            speedDataDict['errorId'] = parseInt(speedDataDict['errorId']) + 1;
            speedDataDict['field'] = 'value';
            speedDataDict['error'] = commonErrorkeyArray[2];

            // speedErrors[index] = new ValidationError('No field: value').message;
        }

    });

    // return speedErrors;
    return speedDataDict;

}

//validate temp name and value
function checkTempData(temperatureArrayData) {
    var temperatureErrors = {}


    temperatureArrayData.forEach((element, index) => {
        if ('name' in element) {
            // console.log(element.name);
        }
        else {
            temperatureErrors[index] = new ValidationError("No field: name").message;
        }

        if ('value' in element) {
            // console.log(element.value);

            //check if value is more than 00
            // if (element.value > 0) {
            //     console.log("temperature value more than 0: ", elem.value);
            // }
            // else {
            //     temperatureErrors[index] = new ValidationError('Temperature cannot be less than 0').message;
            // }

        }
        else {
            temperatureErrors[index] = new ValidationError("No field: value").message;
        }
    });

    return temperatureErrors;
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
