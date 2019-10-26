/*

Query the total population of all cities in CITY where District is California.

*/

select SUM(POPULATION) from CITY where DISTRICT = 'California';