SELECT w2.Id
FROM Weather as w1, Weather as w2
WHERE datediff(w2.Date, w1.Date)=1 
 AND  w1.temperature < w2.temperature