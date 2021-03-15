require('dotenv').config()
const mongoose = require('mongoose');


import mongoSchema from '../db/pod1models.js';
// const mongoSchema = require("../db/pod1models.js");


const express = require('express');
const app = express();
// const Pod1 = require('../db/pod1models.js')
// let Pod1 = await import('../db/pod1models.js')

mongoose.connect(process.env.DATABASE_URL, { useNewUrlParser: true });
const db = mongoose.connection
db.on('error', (error) => console.error(error))
db.once('open', () => console.log('Connected to Database'))

app.use(express.json())

const pod1Router = require('./routes/pod1.js')
app.use('/pod1', pod1Router)


app.listen(3000, () => { console.log('Server is running...') });

var pod1 = new mongoSchema({
    id: 123,
    speed: 23,
    temp: [
        {
            "sensor": 1,
            "temp": 56
        },
        {
            "sensor": 2,
            "temp": 12
        }
    ],
    batterylevel: [
        {
            "sensor": 1,
            "battery": 56
        },
        {
            "sensor": 2,
            "battery": 12
        }
    ],   
    brakepressure: [
        {
            "sensor": 1,
            "pressure": 56
        },
        {
            "sensor": 2,
            "pressure": 12
        }
    ],
    location: {
        x: 2,
        y: 3,
        z: 13
    }

})

console.log(pod1.temp[0].name)

console.log(pod1);

