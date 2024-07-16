# Write your MySQL query statement below
select a.id
from Weather as a
join Weather as b
on a.recordDate = date_add(b.recordDate, interval 1 day)
where a.temperature>b.temperature;