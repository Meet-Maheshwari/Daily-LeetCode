# Write your MySQL query statement below

Select query_name, round(avg(rating/position),2) as quality, round((sum(rating < 3) * 100 / count(*)),2) as poor_query_percentage from Queries
Group By query_name