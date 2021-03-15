## Pod1 Schema

We are using noSQL (MongoDB with mongoose) to leverage its JSON-like objects to recieve various sensor data (temperature, battery levels, brake pressures, location etc...) and send it to the frontend to display in an intuitive and interactive control panel.

* Schemas are equivalent to the a table in SQL.
* Fields inside a Schema are equivalent to columns in SQL
* Documents are equivalent to rows in SQL
* Models take an instance of a Document equivalent to records in SQL

This [link](https://www.freecodecamp.org/news/introduction-to-mongoose-for-mongodb-d2a7aa593c57/#:~:text=Mongoose%20is%20an%20Object%20Data,of%20those%20objects%20in%20MongoDB.) provides small descriptions of the above terminology.


##  Schema Documentation

Desc: timestamp multiple pod flights.  
Parameters:
  * name: name of pod run
  * lastActiveDate: date of pod run
``` javascript
timeStamp: {
        name: String,
        lastActivDate: Date,

    },
```

Desc: speed of pod  
Parameters:
  * speed: integer or float number representing speed of pod
``` javascript
timeStamp: {
        name: String,
        lastActivDate: Date,

    },
```

Desc: temperature of various applicable components on pod; have a unique id for every temperature component (determined by respective subteam)  
Parameters: a list of temperatures 
  * temp: can take any data type (ex:  
        "sensor": 1,  
        "temp": 56  
    )
``` javascript
    temp: [
        Object
    ],
```

Desc: Battery level of various applicable components on pod; have a unique id for every component (determined by respective subteam)  
Parameters: a list of battery levels
  * batterlevel: can take any data type (ex:  
        "sensor": 1,  
        "battery": 56  
    )
``` javascript
    batterylevel: [
        Object
    ],
```

Desc: brake pressure of various applicable components on pod; have a unique id for every component (determined by respective subteam)  
Parameters: a list of brake pressures
  * brakepressure: can take any data type (ex:  
        "sensor": 1,  
        "pressure": 56  
    )
``` javascript
    brakepressure: [
        Object
    ],
```
Desc: state from state machine is assigned a unique value based on a enumeration class (to be implemented); random integers for now  
Parameters: dictionary of states with assigned numbers
  * debug: pod is in debug mode
  * off: pod is turned off
  * commscheck: pod running through communications checks
  * systemcheck: pod running through system checks
  * lock: pod is in lock mode
  * arm: pod is in arm mode
  * shutdown: pod is initiating shutdown sequence
  * braking: pod is braking
  * estop: pod is initiating emergency stop sequence
  * drive: pod is in drive mode
``` javascript
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
```

Desc: recieveing errors from various sensors/subteams  
Parameters: an Object that can take any data types  
  * errors: list of Objects that can take any data type (ex:  
        "sensor": 1,  
        "error": "battery level exceeding max threshold"  
    )
``` javascript
    errors: [
        Object
    ],
```

Desc: location of pod on the track  
Parameters: dictioanry of the x-location, y-location, and z-location of the pod  
  * x: takes a integer or float value of the x-location of the pod
  * y: takes a integer or float value of the y-location of the pod
  * z: takes a integer or float value of the z-location of the pod
``` javascript
    location: {
        x: {
            type: Number,
        },
        y: {
            type: Number
        },
        z: {
            type: Number,
        }
    }
```
