Select s.Score as Score,
       @rank := @rank + (@prev <> (@prev := s.Score)) as Rank

From Scores s 
     (Select @rank := 0, @prev := -1)
order by s.Score desc