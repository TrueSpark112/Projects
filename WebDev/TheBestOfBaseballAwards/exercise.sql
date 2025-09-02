SELECT * FROM people LIMIT 10;
SELECT * FROM batting LIMIT 10;
SELECT * FROM pitching LIMIT 10;
SELECT * FROM teams LIMIT 10;

SELECT * FROM salaries LIMIT 10;

SELECT teams.name, AVG(people.weight),batting.yearid FROM people
JOIN batting ON people.playerid = batting.playerid
JOIN teams ON batting.teamid = teams.teamid
GROUP BY teams.name, batting.yearid
ORDER BY AVG(people.weight) DESC;

SELECT teams.name, AVG(people.height) AS "avg_height", batting.yearid FROM people
JOIN batting ON people.playerid = batting.playerid
JOIN teams ON batting.teamid = teams.teamid
GROUP BY teams.name, batting.yearid
ORDER BY AVG(people.height) DESC;

SELECT teams.name, SUM(salaries.salary), salaries.yearid FROM salaries
JOIN teams ON salaries.teamid = teams.teamid
GROUP BY teams.name, salaries.yearid
ORDER BY SUM(salaries.salary) DESC;

SELECT teams.name, SUM(salaries.salary)/teams.w AS "cost_per_win", teams.w, salaries.yearid FROM salaries
JOIN teams ON salaries.teamid = teams.teamid
WHERE salaries.yearid=2010
GROUP BY teams.name, teams.w, salaries.yearid
ORDER BY "cost_per_win" ASC;

SELECT people.playerid, pitching.yearid, ROUND((salaries.salary::numeric/pitching.g),2) AS "cost_per_game"
FROM salaries
JOIN pitching 
    ON salaries.playerid = pitching.playerid
    AND salaries.yearid = pitching.yearid 
    AND salaries.teamid = pitching.teamid 
JOIN people ON salaries.playerid = people.playerid
WHERE pitching.gs>10

ORDER BY (salaries.salary::numeric/pitching.g) DESC;