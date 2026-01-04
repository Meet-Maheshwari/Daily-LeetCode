# Write your MySQL query statement below

select DISTINCT num as ConsecutiveNums from Logs
where (num, id+1) in (select num, id from Logs
where (num, id+1) in (select num, id from Logs))