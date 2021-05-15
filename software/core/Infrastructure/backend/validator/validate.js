const { Console } = require("console");
const fs = require("fs");

const lodash = require('lodash');
const commonErrorsDict = require("./commonErrors");

// var commonErrors = fs.readFileSync("./commonErrors.json");
// var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsDict);
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

    brakesThreshold = 200;
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

    currentThreshold = 100;
    var currentDataDict = {
        errorId: error_id,
        dataArrayName: 'currentDataArray',
        entity: globalEntityIncrement,
        thresholdValue: currentThreshold,
        error: ''
    }

    vibrationThreshold = 100;
    var vibrationDataDict = {
        errorId: error_id,
        dataArrayName: 'vibrationDataArray',
        entity: globalEntityIncrement,
        thresholdValue: vibrationThreshold,
        error: ''
    }

    gapHeightThreshold = 100;
    var gapHeightDataDict = {
        errorId: error_id,
        dataArrayName: 'gapHeightDataArray',
        entity: globalEntityIncrement,
        thresholdValue: gapHeightThreshold,
        error: ''
    }

    var accelerationDataDict = {
        errorId: error_id,
        dataArrayName: 'accelerationDataArray',
        entity: globalEntityIncrement,
        error: ''
    }

    if ('speed' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkSpeedData(jsonOdriodData.speed, speedDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
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

    if ('current' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkCurrentData(jsonOdriodData.current, currentDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw current type error
        errorarray.push(sensorTypeError('current', currentDataDict));
        // console.log(errorarray);
    }

    if ('vibration' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkVibrationData(jsonOdriodData.vibration, vibrationDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw current type error
        errorarray.push(sensorTypeError('vibration', currentDataDict));
        // console.log(errorarray);
    }

    if ('gapHeight' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkGapHeightData(jsonOdriodData.gapHeight, gapHeightDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw current type error
        errorarray.push(sensorTypeError('gapHeight', gapHeightDataDict));
        // console.log(errorarray);
    }

    if ('acceleration' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkAccelerationData(jsonOdriodData.acceleration, accelerationDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw current type error
        errorarray.push(sensorTypeError('acceleration', accelerationDataDict));
        // console.log(errorarray);
    }

    return errorarray;
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
        deepDataDict['error'] = commonErrorkeyArray[7];
    }

    //temperatureNotFoundError
    if (sensorType == 'temperatures') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[8];
    }

    //brakeNotFoundError
    if (sensorType == 'brakes') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[10];
    }

    //batteryNotFoundError
    if (sensorType == 'battery') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[11];
    }

    //currentNotFoundError
    if (sensorType == 'current') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[12];
    }

    //vibrationNotFoundError
    if (sensorType == 'vibration') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[13];
    }

    //gapHeightNotFoundError
    if (sensorType == 'gapHeight') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[14];
    }

    //accelerationNotFoundError
    if (sensorType == 'acceleration') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[15];
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
    speedArray = [];
    var entityIncrement = 1;

    speedDataArray.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                var deepSpeedDataDict = lodash.cloneDeep(speedDataDict);

                incremenErrorId();
                deepSpeedDataDict['errorId'] = error_id;
                deepSpeedDataDict['entity'] = entityIncrement;
                deepSpeedDataDict['error'] = commonErrorkeyArray[0];

                speedArray.push(deepSpeedDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepSpeedDataDict = lodash.cloneDeep(speedDataDict);

            incremenErrorId();
            deepSpeedDataDict['errorId'] = error_id;
            deepSpeedDataDict['entity'] = entityIncrement;
            deepSpeedDataDict['error'] = commonErrorkeyArray[2];

            speedArray.push(deepSpeedDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepSpeedDataDict = lodash.cloneDeep(speedDataDict);

            incremenErrorId();
            deepSpeedDataDict['errorId'] = error_id;
            deepSpeedDataDict['entity'] = entityIncrement;
            deepSpeedDataDict['error'] = commonErrorkeyArray[3];

            speedArray.push(deepSpeedDataDict);
        }

    });
    return speedArray;
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
                deepTemperatureDataDict['error'] = commonErrorkeyArray[6];

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
                deepBrakeDataDict['error'] = commonErrorkeyArray[6];

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
                deepbatteryDataDict['error'] = commonErrorkeyArray[6];

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

/**
 * Creates an array of current data error objects by checking name and value of the data
 *
 * @param {Object[]} currentArrayData
 * @param {Object} currentDataDict
 * @returns {Object[]}
 */
function checkCurrentData(currentArrayData, currentDataDict) {
    currentArray = [];
    var entityIncrement = 1;

    currentArrayData.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                var deepCurrentDataDict = lodash.cloneDeep(currentDataDict);

                incremenErrorId();
                deepCurrentDataDict['errorId'] = error_id;
                deepCurrentDataDict['entity'] = entityIncrement;
                deepCurrentDataDict['error'] = commonErrorkeyArray[0];

                currentArray.push(deepCurrentDataDict);
            }
            else if (elem.value > 100) {
                var deepCurrentDataDict = lodash.cloneDeep(currentDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepCurrentDataDict['errorId'] = error_id;
                deepCurrentDataDict['entity'] = entityIncrement;
                deepCurrentDataDict['error'] = commonErrorkeyArray[6];

                currentArray.push(deepCurrentDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepCurrentDataDict = lodash.cloneDeep(currentDataDict);

            incremenErrorId();
            deepCurrentDataDict['errorId'] = error_id;
            deepCurrentDataDict['entity'] = entityIncrement;
            deepCurrentDataDict['error'] = commonErrorkeyArray[2];

            currentArray.push(deepCurrentDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepCurrentDataDict = lodash.cloneDeep(currentDataDict);

            incremenErrorId();
            deepCurrentDataDict['errorId'] = error_id;
            deepCurrentDataDict['entity'] = entityIncrement;
            deepCurrentDataDict['error'] = commonErrorkeyArray[3];

            currentArray.push(deepCurrentDataDict);
        }
    });
    return currentArray;
}

/**
 * Creates an array of vibraiton data error objects by checking name and value of the data
 *
 * @param {Object[]} vibrationArrayData
 * @param {Object} vibrationDataDict
 * @returns {Object[]}
 */
function checkVibrationData(vibrationArrayData, vibrationDataDict) {
    vibrationArray = [];
    var entityIncrement = 1;

    vibrationArrayData.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                var deepVibrationDataDict = lodash.cloneDeep(vibrationDataDict);

                incremenErrorId();
                deepVibrationDataDict['errorId'] = error_id;
                deepVibrationDataDict['entity'] = entityIncrement;
                deepVibrationDataDict['error'] = commonErrorkeyArray[0];

                vibrationArray.push(deepVibrationDataDict);
            }
            else if (elem.value > 100) {
                var deepVibrationDataDict = lodash.cloneDeep(vibrationDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepVibrationDataDict['errorId'] = error_id;
                deepVibrationDataDict['entity'] = entityIncrement;
                deepVibrationDataDict['error'] = commonErrorkeyArray[6];

                vibrationArray.push(deepVibrationDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepVibrationDataDict = lodash.cloneDeep(vibrationDataDict);

            incremenErrorId();
            deepVibrationDataDict['errorId'] = error_id;
            deepVibrationDataDict['entity'] = entityIncrement;
            deepVibrationDataDict['error'] = commonErrorkeyArray[2];

            vibrationArray.push(deepVibrationDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepVibrationDataDict = lodash.cloneDeep(vibrationDataDict);

            incremenErrorId();
            deepVibrationDataDict['errorId'] = error_id;
            deepVibrationDataDict['entity'] = entityIncrement;
            deepVibrationDataDict['error'] = commonErrorkeyArray[3];

            vibrationArray.push(deepVibrationDataDict);
        }
    });
    return vibrationArray;
}

/**
 * Creates an array of vibraiton data error objects by checking name and value of the data
 *
 * @param {Object[]} gapHeightArrayData
 * @param {Object} gapHeightDataDict
 * @returns {Object[]}
 */
function checkGapHeightData(gapHeightArrayData, gapHeightDataDict) {
    gapHeightArray = [];
    var entityIncrement = 1;

    gapHeightArrayData.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                var deepGapHeightDataDict = lodash.cloneDeep(gapHeightDataDict);

                incremenErrorId();
                deepGapHeightDataDict['errorId'] = error_id;
                deepGapHeightDataDict['entity'] = entityIncrement;
                deepGapHeightDataDict['error'] = commonErrorkeyArray[0];

                gapHeightArray.push(deepGapHeightDataDict);
            }
            else if (elem.value > 100) {
                var deepGapHeightDataDict = lodash.cloneDeep(gapHeightDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepGapHeightDataDict['errorId'] = error_id;
                deepGapHeightDataDict['entity'] = entityIncrement;
                deepGapHeightDataDict['error'] = commonErrorkeyArray[6];

                gapHeightArray.push(deepGapHeightDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepGapHeightDataDict = lodash.cloneDeep(gapHeightDataDict);

            incremenErrorId();
            deepGapHeightDataDict['errorId'] = error_id;
            deepGapHeightDataDict['entity'] = entityIncrement;
            deepGapHeightDataDict['error'] = commonErrorkeyArray[2];

            gapHeightArray.push(deepGapHeightDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepGapHeightDataDict = lodash.cloneDeep(gapHeightDataDict);

            incremenErrorId();
            deepGapHeightDataDict['errorId'] = error_id;
            deepGapHeightDataDict['entity'] = entityIncrement;
            deepGapHeightDataDict['error'] = commonErrorkeyArray[3];

            gapHeightArray.push(deepGapHeightDataDict);
        }
    });
    return gapHeightArray;
}

/**
 * Creates an array of vibraiton data error objects by checking name and value of the data
 *
 * @param {Object[]} accelerationArrayData
 * @param {Object} accelerationDataDict
 * @returns {Object[]}
 */
function checkAccelerationData(accelerationArrayData, accelerationDataDict) {
    accelerationArray = [];
    var entityIncrement = 1;

    accelerationArrayData.forEach(elem => {
        // Acceleration CAN BE NEGATIVE
        if (!('value' in elem)) {
            //valueNotFoundError
            var deepAccelerationDataDict = lodash.cloneDeep(accelerationDataDict);

            incremenErrorId();
            deepAccelerationDataDict['errorId'] = error_id;
            deepAccelerationDataDict['entity'] = entityIncrement;
            deepAccelerationDataDict['error'] = commonErrorkeyArray[2];

            accelerationArray.push(deepAccelerationDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepAccelerationDataDict = lodash.cloneDeep(accelerationDataDict);

            incremenErrorId();
            deepAccelerationDataDict['errorId'] = error_id;
            deepAccelerationDataDict['entity'] = entityIncrement;
            deepAccelerationDataDict['error'] = commonErrorkeyArray[3];

            accelerationArray.push(deepAccelerationDataDict);
        }
    });
    return accelerationArray;
}

// var tempdata = fs.readFileSync("./test.json");
// const validateobject = validate(JSON.parse(tempdata));
// console.log(validateobject);
// return validateobject;

module.exports = validate;
