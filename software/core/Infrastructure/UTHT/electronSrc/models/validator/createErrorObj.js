

function createErrorObj(error_array) {

    const groupByDataArray = nestGroupsBy(error_array, ['dataArrayName', 'entity', 'error']);
    var nestedObj = JSON.stringify(groupByDataArray, null, 2);

    return groupByDataArray;

}

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

// var temp = 
// [
//     {
//       errorId: 1,
//       dataArrayName: 'speedDataArray',
//       entity: 1,
//       error: 'negativeValueError'
//     },
//     {
//       errorId: 2,
//       dataArrayName: 'speedDataArray',
//       entity: 1,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 3,
//       dataArrayName: 'temperatureDataArray',
//       entity: 1,
//       thresholdValue: 1000,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 4,
//       dataArrayName: 'temperatureDataArray',
//       entity: 1,
//       thresholdValue: 1000,
//       error: 'valueExceedsThresholdError'
//     },
//     {
//       errorId: 5,
//       dataArrayName: 'brakeDataArray',
//       entity: 1,
//       thresholdValue: 200,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 6,
//       dataArrayName: 'brakeDataArray',
//       entity: 2,
//       thresholdValue: 200,
//       error: 'statusNotFoundError'
//     },
//     {
//       errorId: 7,
//       dataArrayName: 'brakeDataArray',
//       entity: 3,
//       thresholdValue: 200,
//       error: 'pressureNotFoundError'
//     },
//     {
//       errorId: 8,
//       dataArrayName: 'batteryDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 9,
//       dataArrayName: 'batteryDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'valueExceedsThresholdError'
//     },
//     {
//       errorId: 10,
//       dataArrayName: 'batteryDataArray',
//       entity: 2,
//       thresholdValue: 100,
//       error: 'valueNotFoundError'
//     },
//     {
//       errorId: 11,
//       dataArrayName: 'currentDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'valueExceedsThresholdError'
//     },
//     {
//       errorId: 12,
//       dataArrayName: 'currentDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 13,
//       dataArrayName: 'vibrationDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'valueExceedsThresholdError'
//     },
//     {
//       errorId: 14,
//       dataArrayName: 'vibrationDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 15,
//       dataArrayName: 'gapHeightDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'valueExceedsThresholdError'
//     },
//     {
//       errorId: 16,
//       dataArrayName: 'gapHeightDataArray',
//       entity: 1,
//       thresholdValue: 100,
//       error: 'nameNotFoundError'
//     },
//     {
//       errorId: 17,
//       dataArrayName: 'accelerationDataArray',
//       entity: 1,
//       error: 'nameNotFoundError'
//     }
//   ]

// console.log(createErrorObj(temp));

module.exports = createErrorObj;