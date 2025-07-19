# Write your MySQL query statement below

SELECT product_name, year, price from Product, Sales
WHERE Sales.product_id = Product.product_id;