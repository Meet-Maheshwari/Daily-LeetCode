# Write your MySQL query statement below
select x, y, z,
IF(x + y <= z OR x + z <= y OR y + z <= x, 'No', 'Yes') as triangle
from Triangle
