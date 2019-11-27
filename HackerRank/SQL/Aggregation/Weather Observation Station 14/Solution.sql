/*

Query the greatest value of the Northern Latitudes (LAT_N) from STATION that is less than 137.2345. Truncate your answer to 4 decimal places.

*/

SELECT TRUNCATE(MAX(lat_n), 4) FROM STATION WHERE lat_n < 137.2345;