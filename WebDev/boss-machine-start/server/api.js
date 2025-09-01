const express = require('express');
const apiRouter = express.Router();

const {
  createMeeting,
  getAllFromDatabase,
  getFromDatabaseById,
  addToDatabase,
  updateInstanceInDatabase,
  deleteFromDatabasebyId,
  deleteAllFromDatabase,
} = require('./db');

const checkMillionDollarIdea = require('./checkMillionDollarIdea');

apiRouter.get('/minions', (req, res, next) => {
    try{
      res.send(getAllFromDatabase('minions'));
    } catch (error) {
      next(error);
    }
});
apiRouter.post('/minions', (req, res, next) => {
  try {
    const newMinion = req.body;
    const createdMinion = addToDatabase('minions', newMinion);
    res.status(201).send(createdMinion);
  } catch (error) {
    next(error);
  }
});
apiRouter.get('/minions/:minionId', (req, res, next) => {
    try {
        const minion = getFromDatabaseById('minions', req.params.minionId);
        if (minion) {
            res.send(minion);
        } else {
            const error = new Error('Minion not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

apiRouter.put('/minions/:minionId', (req, res, next) => {
    try {
        const updatedMinion = updateInstanceInDatabase('minions', req.body);
        if (updatedMinion) {
            res.send(updatedMinion);
        } else {
            const error = new Error('Minion not found or invalid data');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});
apiRouter.delete('/minions/:minionId', (req, res, next) => {
    try {
        const deleted = deleteFromDatabasebyId('minions', req.params.minionId);
        if (deleted) {
            res.status(204).send();
        } else {
            const error = new Error('Minion not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

apiRouter.get('/ideas', (req, res, next) => {
    try {
        res.send(getAllFromDatabase('ideas'));
    } catch (error) {
        next(error);
    }
});
apiRouter.post('/ideas', checkMillionDollarIdea, (req, res, next) => {
    try {
        const newIdea = req.body;
        const createdIdea = addToDatabase('ideas', newIdea);
        res.status(201).send(createdIdea);
    } catch (error) {
        next(error);
    }
});

apiRouter.get('/ideas/:ideaId', (req, res, next) => {
    try {
        const idea = getFromDatabaseById('ideas', req.params.ideaId);
        if (idea) {
            res.send(idea);
        } else {
            const error = new Error('Idea not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

apiRouter.put('/ideas/:ideaId', (req, res, next) => {
    try {
        const updatedIdea = updateInstanceInDatabase('ideas', req.body);
        if (updatedIdea) {
            res.send(updatedIdea);
        } else {
            const error = new Error('Idea not found or invalid data');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});
apiRouter.delete('/ideas/:ideaId', (req, res, next) => {
    try {
        const deleted = deleteFromDatabasebyId('ideas', req.params.ideaId);
        if (deleted) {
            res.status(204).send();
        } else {
            const error = new Error('Idea not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

apiRouter.get('/meetings', (req, res, next) => {
    try {
        res.send(getAllFromDatabase('meetings'));
    } catch (error) {
        next(error);
    }
});
apiRouter.post('/meetings', (req, res, next) => {
    try {
        const newMeeting = createMeeting();
        const createdMeeting = addToDatabase('meetings', newMeeting);
        res.status(201).send(createdMeeting);
    } catch (error) {
        next(error);
    }
});
apiRouter.delete('/meetings', (req, res, next) => {
    try {
        const deleted = deleteAllFromDatabase('meetings');
        if (deleted) {
            res.status(204).send();
        } else {
            const error = new Error('Meetings not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

// BONUS: /api/minions/:minionId/work routes

apiRouter.get('/minions/:minionId/work', (req, res, next) => {
    try {
        const minionId = req.params.minionId;
        const allWork = getAllFromDatabase('work');
        const minionWork = allWork.filter(work => work.minionId === minionId);
        if (minionWork.length > 0) {
            res.send(minionWork);
        } else {
            const error = new Error('Minion work not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});
apiRouter.post('/minions/:minionId/work', (req, res, next) => {
    try {
        const minionId = req.params.minionId;
        const newWork = req.body;
        newWork.minionId = minionId;
        const createdWork = addToDatabase('work', newWork);
        res.status(201).send(createdWork);
    } catch (error) {
        next(error);
    }
});
apiRouter.put('/minions/:minionId/work/:workId', (req, res, next) => {
    try {
        const workId = req.params.workId;  // Keep as string, don't convert to Number
        const minionId = req.params.minionId;  // Keep as string, don't convert to Number
        let updatedWork = req.body;

        // Set the ID and minionId from the URL parameters
        updatedWork.id = workId;
        updatedWork.minionId = minionId;

        // First check if the work item exists
        const existingWork = getFromDatabaseById('work', workId);
        if (!existingWork) {
            const error = new Error('Work not found');
            error.status = 404;
            return next(error);
        }

        // Check if the existing work belongs to the correct minion
        if (existingWork.minionId !== minionId) {
            const error = new Error('Minion ID mismatch');
            error.status = 400;
            return next(error);
        }

        const result = updateInstanceInDatabase('work', updatedWork);
        if (result) {
            res.send(result);
        } else {
            const error = new Error('Work not found or invalid data');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

apiRouter.delete('/minions/:minionId/work/:workId', (req, res, next) => {
    try {
        const workId = req.params.workId;
        const deleted = deleteFromDatabasebyId('work', workId);
        if (deleted) {
            res.status(204).send();
        } else {
            const error = new Error('Work not found');
            error.status = 404;
            next(error);
        }
    } catch (error) {
        next(error);
    }
});

//error handler
apiRouter.use((error, req, res, next) => {
  console.error(error);
  if(error.status){
    res.status(error.status).send({ error: error.message });
  } else {
    res.status(500).send({ error: 'Internal Server Error' });
  }
});

module.exports = apiRouter;
