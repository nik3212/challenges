{-|

You are given a list. Return the sum of odd elements from the given list. The input and output portions will be handled automatically. You need to write a function with the recommended method signature.

Constraints

The list will have 1 - 100 elements. 
Each element will be an integer X where -100 <= X <= 100.

Sample Input

3
2
4
6
5
7
8
0
1

Sample Output

16

Explanation

Sum of odd elements is 3 + 5 + 7 + 1 = 16

Method Signature

Number Of Parameters: 1
Parameters: [list]
Returns: Number

-}

sum' :: [Int] -> Int
sum' [] = 0
sum' (x:xs) = x + sum' xs

f arr = sum' [num | num <- arr, odd num]

-- This part handles the Input/Output and can be used as it is. Do not change or modify it.
main = do
	inputdata <- getContents
	putStrLn $ show $ f $ map (read :: String -> Int) $ lines inputdata