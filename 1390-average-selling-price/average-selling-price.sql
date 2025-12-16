# Write your MySQL query statement below

SELECT p.product_id, round(ifnull(sum(p.price * u.units)/sum(u.units), 0), 2) as average_price from Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date >= p.start_date
AND u.purchase_date <= p.end_date
GROUP BY p.product_id