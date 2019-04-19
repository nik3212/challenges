/*

Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION. Your result cannot contain duplicates.

*/

select distinct CITY from STATION where right(CITY, 1) in ('a', 'i', 'e', 'o', 'u');