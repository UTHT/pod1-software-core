const express = require('express')
const router = express.Router()

//May not need routes, could implement directly in websockets
    //could implement in future
    
// Getting all
router.get('/', (req, res) => {
    res.send('Hello World')
})



// Getting one
router.get('/:id', (req, res) => {
    res.send(req.params.id)
})

// Creating one
router.post('/', (req, res) => {

})

// updating one
router.get('/:id', (req, res) => {

})

// Deleting one
router.delete('/:id', (req, res) => {

})

module.exports = router