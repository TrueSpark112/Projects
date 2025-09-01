const express = require('express');
const app = express();

module.exports = app;
const cors = require('cors');
const bodyParser = require('body-parser');

// Add middleware for handling CORS requests from index.html
app.use(cors());
// Add middleware for parsing request bodies here:
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));


// Mount your existing apiRouter below at the '/api' path.
const apiRouter = require('./server/api');
app.use('/api', apiRouter);
