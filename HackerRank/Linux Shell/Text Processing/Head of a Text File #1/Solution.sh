# In this challenge, we practice using the head command to display the first n lines of a text file.
#
# Display the first 20 lines of an input file.
#
# Input Format
#
# A text file.
#
# Output Format
#
# Output the first 20 lines of the given text file.

cat | cut -d$'\n' -f -20