var express = require('express');
var bodyParser = require('body-parser');
var app = express('mongoose');

var http = require('http').Server(app);
var io = require('socket.io')(http);
var mongoose = require('mongoose');

app.use(express.static(__dirname));
app.use(bodyParser.json())
app.use(bodyParser.urlencoded({ extended: false }))


// to avoid deprecation 
mongoose.Promise = Promise;

var dbUrl = 'mongodb://admin:a113355@ds133981.mlab.com:33981/chatbot';
// To prevent Depreciation warnings (From Database)
var avoidDeprecation = { useUnifiedTopology: true, useNewUrlParser: true, useCreateIndex: true }

// Message Model
var Message = mongoose.model('Message', {
    name: String,
    message: String
})

// var messages = [
//     { name: 'Tim', message: 'Hi' },
//     { name: 'Jane', message: 'Hello' }
// ]

app.get('/messages', (req, res) => {
    Message.find({}, (err, messages) => {
        res.send(messages);
    })
})

app.get('/messages/:user', (req, res) => {
    var user = req.params.user
    Message.find({name: user}, (err, messages) => {
        res.send(messages);
    })
})

app.post('/messages', (req, res) => {
    var message = new Message(req.body)
    message.save().then(() => {

        // messages.push(req.body);
        io.emit('message', req.body)
        res.sendStatus(200)
    }).catch((err) => {
        res.sendStatus(500)
        return console.error(err)
    })
})

io.on('connection', (socket) => {
    console.log('A user connected')
})


mongoose.connect(dbUrl, avoidDeprecation).then((err) => {
    console.log('Connection to database sucessfully');
}).catch((error) => {
    console.log("Error while attempting to conect to Database" + error);
})

var server = http.listen(3000, () => {
    console.log('Server is listening on port', server.address().port)
});