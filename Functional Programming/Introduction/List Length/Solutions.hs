{-|

Count the number of elements in an array without using count, size or length operators (or their equivalents). The input and output portions will be handled automatically by the grader. You only need to write a function with the recommended method signature.

Input Format

A list of N integers, each on a separate line.

Output Format

Output a single integer , the length of the list that was provided as input.

Sample Input

2
5
1
4
3
7
8
6
0
9

Sample Output

10

Constraints

0 <= N <= 100
Each element, X, in the list: 0 <= X <= 100

Recommended Method Signature

Number Of Parameters: 1
Parameters: [list]
Returns: Number

-}

len :: [a] -> Int
len [] = 0
len (x:xs) = 1 + len xs