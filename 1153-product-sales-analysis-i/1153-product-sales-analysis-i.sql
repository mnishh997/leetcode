# Write your MySQL query statement below
#product_id is common in both
# try to do left join so that har product ke liye ek naam aa jaaye

select product_name, year,price from Sales as a
left join Product as b
on a.product_id = b.product_id;
