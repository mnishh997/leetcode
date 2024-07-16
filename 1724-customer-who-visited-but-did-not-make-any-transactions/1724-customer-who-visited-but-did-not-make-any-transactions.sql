# Write your MySQL query statement below
# I will do a left join

select customer_id, count(customer_id) as count_no_trans from Visits as a
left join Transactions as b
on a.visit_id = b.visit_id
where b.transaction_id is null
group by a.customer_id;