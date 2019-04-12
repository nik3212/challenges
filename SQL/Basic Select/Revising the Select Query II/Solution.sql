/*

Query the names of all American cities in CITY with populations larger than 120000. The CountryCode for America is USA.

*/

select NAME from CITY where (COUNTRYCODE = 'USA' and POPULATION > 120000);