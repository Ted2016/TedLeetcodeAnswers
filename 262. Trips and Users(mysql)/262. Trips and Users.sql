# Write your MySQL query statement below
Select t.Request_at as Day,
       ROUND(count(if(t.Status != "completed", TRUE, NULL))/count(t.Status), 2) as 'Cancellation Rate'
From (Select Users_Id
      From Users 
      Where Banned = 'No'
            and Role = 'client') clients join Trips t
      on clients.Users_Id = t.client_Id
Where t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
      group by t.Request_at