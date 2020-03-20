/**
 * Primary file for the API
 * 
 */

// Dependencies
const http = require('http');
const url = require('url');
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

    // Send the response 
    res.end('Hello World\n');

    // Log the request path
    // console.log('Request recived on path:' + trimmedPath + ' Method:' + method + ' query parameteres: ', queryStringObject);
    console.log('Request recived with these headers:' + JSON.stringify(headers));
});

// Start the server, and have it listen on port 3000
server.listen(port, () => {
    console.log(`The server is listening on port ${port} now`);
})