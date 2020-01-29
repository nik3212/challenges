# Given a tab delimited file with several columns (tsv format) print the fields from second fields to last field.
#
# Input Format
#
# A tab-separated file with lines of ASCII text only.
#
# Constraints
#
# 1 <= N <= 100
# 2 <= C <= 100
#
# (N is the number of lines of text in the input file and C is the number of columns of data in the file)
#
# Output Format
#
# The output should contain N lines.
#
# For each line in the input, print the fields from second fields to last field.

cut -f2-