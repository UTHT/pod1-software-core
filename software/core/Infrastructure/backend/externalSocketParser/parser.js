/**
 * The function converts the String receiving from Odroid or JSON from Angular 
 * and return JSON Object 
 * @param {String} externalJson: String object recieving from the Odroid or JSON 
 * object from Angular
 * @returns {Object}; return JSON Object for manipulation by backend
 */

const JSONParser = (externalJson) => {
    if (
        typeof externalJson === "string" &&
        externalJson !== null 
    )

    {
        let dataPreparation = externalJson.replace(/'/g, '"');
        let JSONobject = JSON.parse(dataPreparation);
        return JSONobject;

    } else {
        return externalJson;
    }
}

module.exports = {
    JSONParser
}