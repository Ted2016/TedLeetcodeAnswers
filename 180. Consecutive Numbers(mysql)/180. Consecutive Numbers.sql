# Write your MySQL query statement below
Select distinct l1.Num as ConsecutiveNums
From Logs l1, Logs l2, Logs l3
Where l1.Id = l2.Id-1 and l2.Id = l3.Id-1
      and l1.Num = l2.Num and l2.Num = l3.Num