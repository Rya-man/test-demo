const http = require('http');
const os = require('os');
const path = require('path');
const Event = require('events');

const server = http.createServer((r, res) => {
  res.writeHead(200, { 'Content-Type': 'text/plain' });
  res.end('Hello, Wowqw23q111rld!\n');
});

server.listen(8080, 'localhost', () => {
  console.log('Server running at http://localhost:8080/');
});

console.log('OS Info:', os.type(), os.platform(), os.arch());
console.log('CPU Cores:', os.cpus().length);
console.log('CWD:', process.cwd());
console.log('Path:', path.join(__dirname, 'public', 'images'));

const eventEmitter = new Event();
eventEmitter.on('customEvent', data => console.log('Custom Event:', data));
eventEmitter.emit('customEvent', { message: 'Hello from custom event!' });
