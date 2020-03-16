# You are given a file of pipe-delimited weather data (TSV). There is no header column in this data file. The first five columns of this data are: (a) the name of the city (b) the average monthly temperature in Jan (in Fahreneit). (c) the average monthly temperature in April (in Fahreneit). (d) the average monthly temperature in July (in Fahreneit). (e) the average monthly temperature in October (in Fahreneit).
#
# You need to sort this file in descending order of the second column (i.e. the average monthly temperature in January).
#
# Input Format
#
# A text file with multiple lines of pipe-delimited data. The first five fields have been explained above
#
# Output Format
#
# Sort the data in descending order of the average monthly temperature in January.

sort -t'|' -nrk2