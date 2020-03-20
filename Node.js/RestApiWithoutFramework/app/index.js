/**
 * Primary file for the API
 * 
 */

// Dependencies
const http = require('http');
const url = require('url');
const StringDecoder = require('string_decoder').StringDecoder;
const port = 3000;

// The Server should respond to all requests with a string
const server = http.createServer((req, res) => {

    // Get the URL and parse it
    var parsedUrl = url.parse(req.url, true);

    // Get the path
    var path = parsedUrl.pathname;
    var trimmedPath = path.replace(/^\/+|\/+$/g, '')

    // Get the query string as an object
    var queryStringObject = parsedUrl.query;

    // Get the HTTP Method
    var method = req.method.toLowerCase();

    // Get the headers as an Object
    var headers = req.headers;

    // Get the payload, if any
    var decoder = new StringDecoder('utf-8');
    var buffer = '';
    req.on('data', (data) => {
        buffer += decoder.write(data);
    });

    req.on('end', () => {
        buffer += decoder.end();

        // Choose the handler, which this request should go to
        var chosenHandler = typeof (router[trimmedPath]) !== 'undefined' ? router[trimmedPath] : handlers.notFound;

        // Constract the data object to send the handler
        var data = {
            'trimmedPath': trimmedPath,
            'queryStringObject': queryStringObject,
            'method': method,
            'headers': headers,
            'payload': buffer
        }

        // Route the request to the handler specified in the router
        chosenHandler(data, (statusCode, payload) => {
            // use the status code called back by the handler or default to 200 
            statusCode = typeof (statusCode) == 'number' ? statusCode : 200;

            // use the status code called back by the handler or default to an empty object
            payload = typeof (payload) == 'object' ? payload : {}

            // convert the payload to a string
            var payLoadString = JSON.stringify(payload);

            // Return the response
            res.writeHead(statusCode);
            res.end(payLoadString);

            // Log the request path
            // console.log('Request recived on path:' , trimmedPath );
            // console.log(' Method:' , method );
            // console.log(' query parameteres: ', queryStringObject);
            // console.log('Request recived with these headers:' , JSON.stringify(headers));
            // console.log('Request recived with this payload:' , buffer);
            console.log('Returning this response: ', statusCode, payLoadString);
        });

    });
});

// Start the server, and have it listen on port 3000
server.listen(port, () => {
    console.log(`The server is listening on port ${port} now`);
})

// Define the handlers
var handlers = {}

// Sample handler
handlers.sample = (data, callback) => {
    callback(406, { 'name': 'sample handler' });
};

// Not found handler
handlers.notFound = (data, callback) => {
    callback(404);
};



// Define a request router
var router = {
    'sample': handlers.sample
}
