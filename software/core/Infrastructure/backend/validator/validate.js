const { Console } = require("console");
const fs = require("fs");

const lodash = require('lodash');

var commonErrors = fs.readFileSync("./commonErrors.json");
var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsParsed);
var error_id = 0;

/**
 * Validate incoming JSON data for structural and syntactical integrity
 * returns an object of errors for each sensor type in jsonOdroidData
 * @param {[Object object] <JSON>} jsonOdriodData 
 * @returns {Object}
 */
function validate(jsonOdriodData) {
    var errorarray = []

    globalEntityIncrement = 0;
    var speedDataDict = {
        errorId: error_id,
        dataArrayName: 'speedDataArray',
        entity: globalEntityIncrement,
        error: ''
    }

    temperatureThreshold = 1000;
    var temperatureDataDict = {
        errorId: error_id,
        dataArrayName: 'temperatureDataArray',
        entity: globalEntityIncrement,
        thresholdValue: temperatureThreshold,
        error: ''
    }

    brakesThreshold = 1000;
    var brakeDataDict = {
        errorId: error_id,
        dataArrayName: 'brakeDataArray',
        entity: globalEntityIncrement,
        thresholdValue: brakesThreshold,
        error: ''
    }

    batteryThreshold = 100;
    var batteryDataDict = {
        errorId: error_id,
        dataArrayName: 'batteryDataArray',
        entity: globalEntityIncrement,
        thresholdValue: batteryThreshold,
        error: ''
    }

    if ('speed' in jsonOdriodData) {
        errorarray.push(checkSpeedData(jsonOdriodData.speed, speedDataDict));
        // console.log(errorarray);
    }
    else {
        //throw speed type error
        errorarray.push(sensorTypeError('speed', speedDataDict));
        // console.log(errorarray);
    }

    if ('temperatures' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkTempData(jsonOdriodData.temperatures, temperatureDataDict);
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw temprature type error
        errorarray.push(sensorTypeError('temperatures', temperatureDataDict));
        // console.log(errorarray);
    }
    // NOT CHECKING FOR NOW
    // if ('position' in jsonOdriodData) {
    //     // errorarray.push(checkPositionData(jsonOdriodData.position));
    //     // consol.log(checkPositionData(jsonOdriodData.position));
    //     // console.log(errorarray);
    // }
    // else {
    //     //throw position type error
    //     // errorarray.push(new ValidationError('No field: position').message);
    // }

    if ('brakes' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkBrakeData(jsonOdriodData.brakes, brakeDataDict);
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw brakes type error
        errorarray.push(sensorTypeError('brakes', brakeDataDict));
        // console.log(errorarray);
    }

    if ('battery' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkBatteryData(jsonOdriodData.battery, batteryDataDict);
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw battery type error
        errorarray.push(sensorTypeError('battery', batteryDataDict));
        // console.log(errorarray);

    }

    const groupByDataArray = nestGroupsBy(errorarray, ['dataArrayName', 'entity', 'error']);
    var nestedObj = JSON.stringify(groupByDataArray, null, 2);
    return nestedObj;

}
//the following two function convert the error array into an array with nested objects

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
    return conversions.reduce((accumulate, obj) => {
        let key = obj[property];
        if (!accumulate[key]) {
            accumulate[key] = [];
        }
        delete obj.dataArrayName;
        accumulate[key].push(obj);
        return accumulate;
    }, {});
}

//increment error id
/**
 * Increments the error id for every error encountered
 *
 * @returns {int}
 */
function incremenErrorId() {
    error_id++;
}

/**
 * Creates an error object for appropriate sensors that are not found in original json data
 *
 * @param {String} sensorType
 * @param {Object} dataDict
* @returns {Object}
 */
function sensorTypeError(sensorType, dataDict) {
    var deepDataDict = lodash.cloneDeep(dataDict);

    //speedNotFoundError
    if (sensorType == 'speed') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[6];
    }

    //temperatureNotFoundError
    if (sensorType == 'temperatures') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[7];
    }

    //brakeNotFoundError
    if (sensorType == 'brakes') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[9];
    }

    //batteryNotFoundError
    if (sensorType == 'battery') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[10];
    }

    return deepDataDict
}

/**
 * Creates a speed data error object by checking name and value of the data
 *
 * @param {Object[]} speedDataArray
 * @param {Object} speedDataDict
 * @returns {Object}
 */
function checkSpeedData(speedDataArray, speedDataDict) {
    var deepSpeedDataDict = lodash.cloneDeep(speedDataDict);
    var entityIncrement = 1;

    speedDataArray.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                incremenErrorId();
                deepSpeedDataDict['errorId'] = error_id;
                deepSpeedDataDict['entity'] = entityIncrement;
                entityIncrement++;
                deepSpeedDataDict['error'] = commonErrorkeyArray[0];
            }
        }
        else {
            //valueNotFoundError
            incremenErrorId();
            deepSpeedDataDict['errorId'] = error_id;
            deepSpeedDataDict['entity'] = entityIncrement;
            entityIncrement++;
            deepSpeedDataDict['error'] = commonErrorkeyArray[2];
        }

    });
    return deepSpeedDataDict;
}

/**
 * Creates an array of temperature data error objects by checking name and value of the data
 *
 * @param {Object[]} temperatureArrayData
 * @param {Object} temperatureDataDict
 * @returns {Object[]}
 */
function checkTempData(temperatureArrayData, temperatureDataDict) {
    var entityIncrement = 1;
    temperatureArray = [];

    temperatureArrayData.forEach(element => {
        if ('name' in element) {
        }
        else {
            //nameNotFoundError
            var deepTemperatureDataDict = lodash.cloneDeep(temperatureDataDict);

            incremenErrorId();
            deepTemperatureDataDict['errorId'] = error_id;
            deepTemperatureDataDict['entity'] = entityIncrement;
            deepTemperatureDataDict['error'] = commonErrorkeyArray[3];

            temperatureArray.push(deepTemperatureDataDict);
        }

        if ('value' in element) {
            //check if value is more than 0
            var deepTemperatureDataDict = lodash.cloneDeep(temperatureDataDict);

            if (element.value < 0) {
                //negativeValueError                
                incremenErrorId();
                deepTemperatureDataDict['errorId'] = error_id;
                deepTemperatureDataDict['entity'] = entityIncrement;
                deepTemperatureDataDict['error'] = commonErrorkeyArray[0];

                temperatureArray.push(deepTemperatureDataDict);
            }
            else if (element.value > 1000) {
                var deepTemperatureDataDict = lodash.cloneDeep(temperatureDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepTemperatureDataDict['errorId'] = error_id;
                deepTemperatureDataDict['entity'] = entityIncrement;
                deepTemperatureDataDict['error'] = commonErrorkeyArray[11];

                temperatureArray.push(deepTemperatureDataDict);
            }

        }
        else {
            //valueNotFoundError
            var deepTemperatureDataDict = lodash.cloneDeep(temperatureDataDict);

            incremenErrorId();
            deepTemperatureDataDict['errorId'] = error_id;
            deepTemperatureDataDict['entity'] = entityIncrement;
            deepTemperatureDataDict['error'] = commonErrorkeyArray[2];

            temperatureArray.push(deepTemperatureDataDict);
        }
        entityIncrement++;

    });
    return temperatureArray;
}


//validate position value
//NOT CHECKING AT THE MOMENT
// function checkPositionData(positionArrayData) {
//     var positionErrors = {}

//     positionArrayData.forEach((elem, index) => {
//         if (elem > 0) {
//             // console.log(elem);
//         }
//         else if (elem < 0) {
//             positionErrors[index] = new ValidationError("Position cannot be less than 0").message;
//         }
//         else {
//             positionErrors[index] = new ValidationError("No values provided for position").message;
//         }
//     });

//     return positionErrors;
// }

/**
 * Creates an array of brake data error objects by checking name, value, and pressure of the data
 *
 * @param {Object[]} brakeArrayData
 * @param {Object} brakeDataDict
 * @returns {Object[]}
 */
function checkBrakeData(brakeArrayData, brakeDataDict) {
    var entityIncrement = 1;
    brakeArray = [];

    brakeArrayData.forEach(element => {
        if ('name' in element) {
        }
        else {
            //nameNotFoundError
            var deepBrakeDataDict = lodash.cloneDeep(brakeDataDict);

            incremenErrorId();
            deepBrakeDataDict['errorId'] = error_id;
            deepBrakeDataDict['entity'] = entityIncrement;
            deepBrakeDataDict['error'] = commonErrorkeyArray[3];

            brakeArray.push(deepBrakeDataDict);
        }

        if ('status' in element) {
        }
        else {
            //statusNotFoundError
            var deepBrakeDataDict = lodash.cloneDeep(brakeDataDict);

            incremenErrorId();
            deepBrakeDataDict['errorId'] = error_id;
            deepBrakeDataDict['entity'] = entityIncrement;
            deepBrakeDataDict['error'] = commonErrorkeyArray[4];

            brakeArray.push(deepBrakeDataDict);
        }

        if ('pressure' in element) {
            //check if pressure is more than 0
            var deepBrakeDataDict = lodash.cloneDeep(brakeDataDict);

            if (element.pressure < 0) {
                //negativeValueError                
                incremenErrorId();
                deepBrakeDataDict['errorId'] = error_id;
                deepBrakeDataDict['entity'] = entityIncrement;
                deepBrakeDataDict['error'] = commonErrorkeyArray[0];

                brakeArray.push(deepBrakeDataDict);
            }
            else if (element.pressure > 1000) {
                var deepBrakeDataDict = lodash.cloneDeep(brakeDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepBrakeDataDict['errorId'] = error_id;
                deepBrakeDataDict['entity'] = entityIncrement;
                deepBrakeDataDict['error'] = commonErrorkeyArray[11];

                brakeArray.push(deepBrakeDataDict);
            }

        }
        else {
            //pressureNotFoundError
            var deepBrakeDataDict = lodash.cloneDeep(brakeDataDict);

            incremenErrorId();
            deepBrakeDataDict['errorId'] = error_id;
            deepBrakeDataDict['entity'] = entityIncrement;
            deepBrakeDataDict['error'] = commonErrorkeyArray[5];

            brakeArray.push(deepBrakeDataDict);
        }
        entityIncrement++;

    });
    return brakeArray;

}

/**
 * Creates an array of battery data error objects by checking name and value of the data
 *
 * @param {Object[]} batteryArrayData
 * @param {Object} batteryDataDict
 * @returns {Object[]}
 */
function checkBatteryData(batteryArrayData, batteryDataDict) {
    var entityIncrement = 1;
    batteryArray = [];

    batteryArrayData.forEach(element => {
        if ('name' in element) {
        }
        else {
            //nameNotFoundError
            var deepbatteryDataDict = lodash.cloneDeep(batteryDataDict);

            incremenErrorId();
            deepbatteryDataDict['errorId'] = error_id;
            deepbatteryDataDict['entity'] = entityIncrement;
            deepbatteryDataDict['error'] = commonErrorkeyArray[3];

            batteryArray.push(deepbatteryDataDict);
        }

        if ('value' in element) {
            //check if value is more than 0
            var deepbatteryDataDict = lodash.cloneDeep(batteryDataDict);

            if (element.value < 0) {
                //negativeValueError
                incremenErrorId();
                deepbatteryDataDict['errorId'] = error_id;
                deepbatteryDataDict['entity'] = entityIncrement;
                deepbatteryDataDict['error'] = commonErrorkeyArray[0];

                batteryArray.push(deepbatteryDataDict);
            }
            else if (element.value > 100) {
                var deepbatteryDataDict = lodash.cloneDeep(batteryDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepbatteryDataDict['errorId'] = error_id;
                deepbatteryDataDict['entity'] = entityIncrement;
                deepbatteryDataDict['error'] = commonErrorkeyArray[11];

                batteryArray.push(deepbatteryDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepbatteryDataDict = lodash.cloneDeep(batteryDataDict);

            incremenErrorId();
            deepbatteryDataDict['errorId'] = error_id;
            deepbatteryDataDict['entity'] = entityIncrement;
            deepbatteryDataDict['error'] = commonErrorkeyArray[2];

            batteryArray.push(deepbatteryDataDict);
        }
        entityIncrement++;

    });
    return batteryArray;

}


// var tempdata = fs.readFileSync("./test.json");
// const validateobject = validate(JSON.parse(tempdata));
// console.log(validateobject);

module.exports = validate;