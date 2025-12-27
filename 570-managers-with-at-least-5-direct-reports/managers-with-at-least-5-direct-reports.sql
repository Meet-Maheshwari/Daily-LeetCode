# Write your MySQL query statement below

select name
from Employee 
where id IN (
    select managerId from Employee
    Group by managerId
    having count(managerId) >= 5
)