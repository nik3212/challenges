/*

P(R) represents a pattern drawn by Julia in R rows. The following pattern represents P(5):

* * * * * 
* * * * 
* * * 
* * 
*

Write a query to print the pattern P(20).

*/

set @i = 21;
select repeat('* ', @i := @i - 1) from information_schema.tables;