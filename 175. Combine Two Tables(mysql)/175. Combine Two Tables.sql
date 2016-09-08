# Write your MySQL query statement below
SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
left join Address on Address.PersonId = Person.PersonId