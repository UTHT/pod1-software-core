/**
 * The function converts the String receiving from Odroid or JSON from Angular 
 * and return JSON Object 
 * @param {String} externalJson: String object recieving from the Odroid or JSON 
 * object from Angular
 * @returns {Object}; return JSON Object for manipulation by backend
 */

const JSONParser = (externalJson) => {
    // If incoming data is from Odroid
    if (
        externalJson !== null  &&
        typeof externalJson === "string"
    )

    {
        let dataPreparation = externalJson.replace(/'/g, '"');
        console.log('comeshere')
        let JSONobject = JSON.parse(dataPreparation);
        return JSONobject;

    } else {
        // If incoming data is from dashbord
        return JSON.parse(externalJson);
    }
}

module.exports = JSONParser;