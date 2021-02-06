const mongoose = require('mongoose')

const pod1Schema = new mongoose.Schema({
    /*
    ID for every sensor is dictated by the appropriate subteam and will be in a specific range
    ex: Braking (range 100-200), Battery (range 200-300) etc...
    NEED TO DO ERROR CHECKING BEFORE INPUTTING TEMP, BATTERY LEVEL, and BRAKE PRESSURE
    */

    /*
    Desc: timestamp multiple pod flights
    Parameters:
        name: name of pod run
        lastActiveDate: date of pod run
    */
    timeStamp: {
        name: String,
        lastActiveDate: Date,

    },
    /*
    Desc: speed of pod
    Parameters:
        speed: integer or float number representing speed of pod
    */
    speed: [
        Object,
    ],
    /*
    Desc: temperature of various applicable components on pod; have a unique id for every 
    temperature component (determined by respective subteam)
    Parameters: a list of temperatures
        temp: can take any data type (ex:
            "sensor": 1,
            "temp": 56
        )
    */
    temperature: [
        Object
    ],

    /*
    Desc: Battery level of various applicable components on pod; have a unique id for every 
    component (determined by respective subteam)
    Parameters: a list of battery levels
        batterlevel: can take any data type (ex:
            "sensor": 1,
            "battery": 56
        )
    */
    batterylevel: [
        Object
    ],

    /*
    Desc: brake pressure of various applicable components on pod; have a unique id for every 
    component (determined by respective subteam)
    Parameters: a list of brake pressures
        brakepressure: can take any data type (ex:
            "sensor": 1,
            "pressure": 56
        )
    */
    brakepressure: [
        Object
    ],

    /*
    Desc: state from state machine is assigned a unique value based on a
    enumeration class (to be implemented); random integers for now
    Parameters: dictionary of states with assigned numbers
        debug: pod is in debug mode
        off: pod is turned off
        commscheck: pod running through communications checks
        systemcheck: pod running through system checks
        lock: pod is in lock mode
        arm: pod is in arm mode
        shutdown: pod is initiating shutdown sequence
        braking: pod is braking
        estop: pod is initiating emergency stop sequence
        drive: pod is in drive mode
    */
    podstate: {
        debug: {
            type: Number
        },
        off: {
            type: Number
        },
        commmscheck: {
            type: Number
        },
        systemcheck: {
            type: Number
        },
        lock: {
            type: Number
        },
        arm: {
            type: Number
        },
        shutdown: {
            type: Number
        },
        braking: {
            type: Number
        },
        estop: {
            type: Number
        },
        drive: {
            type: Number
        },

    },

    /*
    Desc: recieveing errors from various sensors/subteams
    Parameters: an Object that can take any data types
        errors: list of Objects that can take any data type (ex:
            "sensor": 1,
            "error": "battery level exceeding max threshold"
        )
    */
    errors: [
        Object
    ],

        /*
    Desc: location of pod on the track
    Parameters: dictioanry of the x-location, y-location, and z-location of the pod
        x: takes a integer or float value of the x-location of the pod
        y: takes a integer or float value of the y-location of the pod
        z: takes a integer or float value of the z-location of the pod
    */
    location: {
        array: {type: [Number]}
    }
});

// export const mongoSchema = mongoose.model('pod1', pod1Schema);

module.exports = mongoose.model('mongoSchema', pod1Schema);
// module.exports = {
//     pod1Schema
// };