/**
 * Primary file for the API
 * 
 */

// Dependencies
const http = require('http');
const port = 3000;

// The Server should respond to all requests with a string
const server = http.createServer((req, res) => {
    console.log('Hello World\n');
});

// Start the server, and have it listen on port 3000
server.listen(port, () => {
    console.log(`The server is listening on port ${port} now`);
})