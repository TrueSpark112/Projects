const checkMillionDollarIdea = (req,res,next) => {
    if (!req.body || !req.body.numWeeks || !req.body.weeklyRevenue) {
        return res.status(400).send({ error: 'Missing required fields' });
    }
    if (req.body.numWeeks * req.body.weeklyRevenue >= 1000000) {
        next();
    } else {
        res.status(400).send({ error: 'Idea does not meet million dollar criteria' });
    }
};

// Leave this exports assignment so that the function can be used elsewhere
module.exports = checkMillionDollarIdea;
