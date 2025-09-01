const express = require('express');
const app = express();

const { quotes } = require('./data');
const { getRandomElement } = require('./utils');

const PORT = process.env.PORT || 4001;

app.use(express.static('public'));

// Most specific route first
app.get('/api/quotes/random', (req, res,next)=> {
  const randomQuote = getRandomElement(quotes);
  res.send(randomQuote);
});

// Modified route to handle query parameters
app.get('/api/quotes', (req, res,next)=> {
  const person = req.query.person; // Get the person from query parameters
  
  if (person) {
    // If person query parameter exists, filter quotes
    const filteredQuotes = quotes.filter(quote => quote.person === person);
    const responseObject = {
      quotes: filteredQuotes,
      person: person,
    };
    res.send(responseObject);
  } else {
    // If no person query parameter, return all quotes
    res.send({
      quotes: quotes
    });
  }
});
app.post('/api/quotes', (req, res,next)=> {
  const newQuote = req.query.quote;
  const newPerson = req.query.person;
  if (!newQuote || !newPerson) {
    return res.status(400).send({ error: 'Quote and person are required' });
  }
  quotes.push({ quote: newQuote, person: newPerson });
  res.status(201).send({ quote: newQuote, person: newPerson });
});

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
