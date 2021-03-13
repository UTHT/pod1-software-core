const { Console } = require("console");
const fs = require("fs");
// const ValidationError = require('./ValidationErrorClass')

const lodash = require('lodash');

var commonErrors = fs.readFileSync("./commonErrors.json");
var commonErrorsParsed = JSON.parse(commonErrors);
var commonErrorkeyArray = Object.keys(commonErrorsParsed);
var error_id = 0;

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

    // test.push(speedDataDict);
    // console.log(test);

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
        console.log(errorarray);
        // errorarray.push(checkBatteryData(jsonOdriodData.battery));
        // console.log(checkBatteryData(jsonOdriodData.brakes));
    }
    else {
        //throw battery type error
        errorarray.push(sensorTypeError('battery', batteryDataDict));
        // console.log(errorarray);

    }


    const groups = nestGroupsBy(errorarray, ['dataArrayName', 'entity', 'error']);
    // console.log(groups);
    // console.log(JSON.stringify(groups, null, 2));

}

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

//increment error id
function incremenErrorId() {
    error_id++;
}

//FIX ERROR ID INCREMENT
//returns error for appropriate sensor that is not found in original json data
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


//validates speed value
function checkSpeedData(speedDataArray, speedDataDict) {
    var deepSpeedDataDict = lodash.cloneDeep(speedDataDict);
    var entityIncrement = 1;

    speedDataArray.forEach(elem => {
        if ('value' in elem) {
            if (elem.value < 0) {
                //negativeValueError
                // var incrementedErrorId = incremenErrorId(error_id);
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

//validate temp name and value
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
            else if (element.pressure > 1000){
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

//function: validate battery name and battery value
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
            else if (element.value > 100){
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

//function: validate podstate ???
//function: validate timeStamp ???



var tempdata = fs.readFileSync("./test.json");
const validateobject = validate(JSON.parse(tempdata));
// console.log(validateobject);

module.exports = validate;


//random test code

// console.log(commonErrorsParsed);
// let first  = commonErrorkeyArray[0];
// console.log(`the key is ${first}`);

// let soMany = commonErrors[0];
// console.log(`This is ${soMany} times easier!`);
