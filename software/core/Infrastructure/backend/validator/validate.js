const { Console } = require("console");
const fs = require("fs");

const lodash = require('lodash');
const commonErrorsDict = require("./commonErrors");

var commonErrorkeyArray = Object.values(commonErrorsDict);

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
    var velocityDataDict = {
        errorId: error_id,
        dataArrayName: 'velocityDataArray',
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

    pressureThreshold = 200;
    var pressureDataDict = {
        errorId: error_id,
        dataArrayName: 'pressureDataArray',
        entity: globalEntityIncrement,
        thresholdValue: pressureThreshold,
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

    var podStateDataDict = {
        errorId: error_id,
        dataArrayName: 'podStateDataArray',
        entity: globalEntityIncrement,
        error: ''
    }

    var positionDataDict = {
        errorId: error_id,
        dataArrayName: 'positionDataArray',
        entity: globalEntityIncrement,
        error: ''
    }

    if ('velocity' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkVelocityData(jsonOdriodData.velocity, velocityDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw speed type error
        errorarray.push(sensorTypeError('velocity', velocityDataDict));
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
    
    if ('position' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkPositionData(jsonOdriodData.position, positionDataDict);
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw brakes type error
        errorarray.push(sensorTypeError('position', positionDataDict));
        // console.log(errorarray);
    }

    if ('pressure' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkPressureData(jsonOdriodData.pressure, pressureDataDict);
        tempArray.forEach(elem => {
            errorarray.push(elem);
        })
        // console.log(errorarray);
    }
    else {
        //throw brakes type error
        errorarray.push(sensorTypeError('pressure', pressureDataDict));
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

    if ('state' in jsonOdriodData) {
        tempArray = [];
        tempArray = checkPodStateData(jsonOdriodData.state, podStateDataDict)
        tempArray.forEach(elem => {
            errorarray.push(elem);
        });
    }
    else {
        //throw current type error
        errorarray.push(sensorTypeError('state', podStateDataDict));
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
    if (sensorType == 'pressure') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[5];
    }

    //batteryNotFoundError
    if (sensorType == 'battery') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[10];
    }

    //currentNotFoundError
    if (sensorType == 'current') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[11];
    }

    //vibrationNotFoundError
    if (sensorType == 'vibration') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[12];
    }

    //gapHeightNotFoundError
    if (sensorType == 'gapHeight') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[13];
    }

    //accelerationNotFoundError
    if (sensorType == 'acceleration') {
        incremenErrorId();
        deepDataDict['errorId'] = error_id;
        deepDataDict['entity'] = sensorType;
        deepDataDict['error'] = commonErrorkeyArray[14];
    }

    //accelerationNotFoundError
    if (sensorType == 'state') {
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
function checkVelocityData(velocityDataArray, velocityDataDict) {
    velocityArray = [];
    var entityIncrement = 1;

    velocityDataArray.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                var deepVelocityDataDict = lodash.cloneDeep(velocityDataDict);

                incremenErrorId();
                deepVelocityDataDict['errorId'] = error_id;
                deepVelocityDataDict['entity'] = entityIncrement;
                deepVelocityDataDict['error'] = commonErrorkeyArray[0];

                velocityArray.push(deepVelocityDataDict);
            }
        }
        else {
            //valueNotFoundError
            var deepVelocityDataDict = lodash.cloneDeep(velocityDataDict);

            incremenErrorId();
            deepVelocityDataDict['errorId'] = error_id;
            deepVelocityDataDict['entity'] = entityIncrement;
            deepVelocityDataDict['error'] = commonErrorkeyArray[2];

            velocityArray.push(deepVelocityDataDict);
        }

        if (!('name' in elem)) {
            //nameNotFoundError
            var deepVelocityDataDict = lodash.cloneDeep(velocityDataDict);

            incremenErrorId();
            deepVelocityDataDict['errorId'] = error_id;
            deepVelocityDataDict['entity'] = entityIncrement;
            deepVelocityDataDict['error'] = commonErrorkeyArray[3];

            velocityArray.push(deepVelocityDataDict);
        }

    });
    return velocityArray;
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


function checkPositionData(positionDataArray, positionDataDict) {
    positionArray = [];
    var entityIncrement = 1;

    positionDataArray.forEach(elem => {
        // if (!('value' in elem)) {
        //     //valueNotFoundError
        //     var deepPositionDataDict = lodash.cloneDeep(positionDataDict);

        //     incremenErrorId();
        //     deepPositionDataDict['errorId'] = error_id;
        //     deepPositionDataDict['entity'] = entityIncrement;
        //     deepPositionDataDict['error'] = commonErrorkeyArray[2];

        //     positionArray.push(deepPositionDataDict);
        // }

        // if (!('name' in elem)) {
        //     //nameNotFoundError
        //     var deepPositionDataDict = lodash.cloneDeep(positionDataDict);

        //     incremenErrorId();
        //     deepPositionDataDict['errorId'] = error_id;
        //     deepPositionDataDict['entity'] = entityIncrement;
        //     deepPositionDataDict['error'] = commonErrorkeyArray[3];

        //     positionArray.push(deepPositionDataDict);
        // }

        entityIncrement++;
    });
    return positionArray;
}
/**
 * Creates an array of brake data error objects by checking name, value, and pressure of the data
 *
 * @param {Object[]} brakeArrayData
 * @param {Object} brakeDataDict
 * @returns {Object[]}
 */
function checkPressureData(pressureArrayData, pressureDataDict) {
    var entityIncrement = 1;
    pressureArray = [];

    pressureArrayData.forEach(element => {
        if (!('name' in element)) {
            //nameNotFoundError
            var deepPressureDataDict = lodash.cloneDeep(pressureDataDict);

            incremenErrorId();
            deepPressureDataDict['errorId'] = error_id;
            deepPressureDataDict['entity'] = entityIncrement;
            deepPressureDataDict['error'] = commonErrorkeyArray[3];

            pressureArray.push(deepPressureDataDict);
        }

        if ('value' in element) {
            //check if value is more than 0
            var deepPressureDataDict = lodash.cloneDeep(pressureDataDict);

            if (element.value < 0) {
                //negativeValueError                
                incremenErrorId();
                deepPressureDataDict['errorId'] = error_id;
                deepPressureDataDict['entity'] = entityIncrement;
                deepPressureDataDict['error'] = commonErrorkeyArray[0];

                pressureArray.push(deepPressureDataDict);
            }
            else if (element.name == "pressure_1000" && element.value >= 1000) {
                // check if pressure for 1000 pressure sensor is more than 1000

                var deepPressureDataDict = lodash.cloneDeep(pressureDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepPressureDataDict['errorId'] = error_id;
                deepPressureDataDict['entity'] = entityIncrement;
                deepPressureDataDict['error'] = commonErrorkeyArray[6];
                deepPressureDataDict['thresholdValue'] = 1000;

                pressureArray.push(deepPressureDataDict);

            }
            else if ((element.name == "pressure_200_1" || element.name == "pressure_200_2")
                && element.value >= 200) {
                // check if pressure for 1000 pressure sensor is more than 1000

                var deepPressureDataDict = lodash.cloneDeep(pressureDataDict);

                //valueExceedsThresholdError
                incremenErrorId();
                deepPressureDataDict['errorId'] = error_id;
                deepPressureDataDict['entity'] = entityIncrement;
                deepPressureDataDict['error'] = commonErrorkeyArray[6];
                deepPressureDataDict['thresholdValue'] = 200;

                pressureArray.push(deepPressureDataDict);

            }
        }
        else {
            //valueNotFoundError
            var deepPressureDataDict = lodash.cloneDeep(pressureDataDict);

            incremenErrorId();
            deepPressureDataDict['errorId'] = error_id;
            deepPressureDataDict['entity'] = entityIncrement;
            deepPressureDataDict['error'] = commonErrorkeyArray[2];

            pressureArray.push(deepPressureDataDict);
        }
        entityIncrement++;
    });
    return pressureArray;

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

        entityIncrement++;

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

        entityIncrement++;

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

        entityIncrement++;

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
        // if (!('value' in elem)) {
        //     //valueNotFoundError
        //     var deepAccelerationDataDict = lodash.cloneDeep(accelerationDataDict);

        //     incremenErrorId();
        //     deepAccelerationDataDict['errorId'] = error_id;
        //     deepAccelerationDataDict['entity'] = entityIncrement;
        //     deepAccelerationDataDict['error'] = commonErrorkeyArray[2];

        //     accelerationArray.push(deepAccelerationDataDict);
        // }

        // if (!('name' in elem)) {
        //     //nameNotFoundError
        //     var deepAccelerationDataDict = lodash.cloneDeep(accelerationDataDict);

        //     incremenErrorId();
        //     deepAccelerationDataDict['errorId'] = error_id;
        //     deepAccelerationDataDict['entity'] = entityIncrement;
        //     deepAccelerationDataDict['error'] = commonErrorkeyArray[3];

        //     accelerationArray.push(deepAccelerationDataDict);
        // }

        entityIncrement++;
    });
    return accelerationArray;
}


function checkPodStateData(podStateDataArray, podStateDataDict) {
    podStateArray = [];
    var entityIncrement = 1;

    podStateDataArray.forEach(elem => {
        // if (!('value' in elem)) {
        //     //valueNotFoundError
        //     var deepPodStateDataDict = lodash.cloneDeep(podStateDataDict);

        //     incremenErrorId();
        //     deepPodStateDataDict['errorId'] = error_id;
        //     deepPodStateDataDict['entity'] = entityIncrement;
        //     deepPodStateDataDict['error'] = commonErrorkeyArray[2];

        //     podStateArray.push(deepPodStateDataDict);
        // }

        // if (!('name' in elem)) {
        //     //nameNotFoundError
        //     var deepPodStateDataDict = lodash.cloneDeep(podStateDataDict);

        //     incremenErrorId();
        //     deepPodStateDataDict['errorId'] = error_id;
        //     deepPodStateDataDict['entity'] = entityIncrement;
        //     deepPodStateDataDict['error'] = commonErrorkeyArray[3];

        //     podStateArray.push(deepPodStateDataDict);
        // }

        entityIncrement++;
    });
    return podStateArray;
}

var tempdata = fs.readFileSync("./test.json");
const validateobject = validate(JSON.parse(tempdata));
console.log(validateobject);
// return validateobject;

module.exports = validate;
