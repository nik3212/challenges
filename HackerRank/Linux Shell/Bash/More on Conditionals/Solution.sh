# Given three integers (X, Y, and Z) representing the three sides of a triangle, identify whether the triangle is Scalene, Isosceles, or Equilateral.
# 
# Input Format
#
# Three integers, each on a new line.
#
# Constraints
#
# 1 <= X, Y, Z <= 1000
#
# Sum of any two sides will be greater than the third.
#
# Output Format
#
# One word: either "SCALENE" or "EQUILATERAL" or "ISOSCELES" (quotation marks excluded).

read a
read b
read c

if [ $a -eq $b ] || [ $a -eq $c ] || [ $c -eq $b ];then
    if [ $((a+b)) -eq $((c*2)) ];then
        echo "EQUILATERAL"
    else
        echo "ISOSCELES"
        fi
else
    echo "SCALENE"
    fi