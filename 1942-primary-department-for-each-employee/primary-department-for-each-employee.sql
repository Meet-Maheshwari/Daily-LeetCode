# Write your MySQL query statement below

select employee_id, department_id from Employee
where primary_flag = "Y"
OR employee_id IN (
    select employee_id from Employee
    group by employee_id
    having count(*) = 1
)