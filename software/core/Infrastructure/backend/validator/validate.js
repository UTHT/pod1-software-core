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


const fs = require("fs");

let data = fs.readFileSync("./test.json");


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


    //call fuctions to check if less than threshold value 
    //call respective component's class to check if type is valid
        //any other fields that are specific to that component
        //is checked in that class

    
/* SKIP FOR NOW
send ALL data to database (regardless of it being correct or incorrect)
set flags in database that indicate correct and incorrect data
integrer flag: 0 for bad and 1 for good
*/

//generate and return error array
///dont return/send the error data further

}


//function: validate speed name
//function: validate speed value
//function: validate temp name
//function: validate temp value
//function: validate position value
//function: validate brake name
//function: validate brake status
//function: validate brake value
//function: validate battery name
//function: validate battery value
//function: validate podstate ???
//function: validate timeStamp ???



module.exports = validate;
