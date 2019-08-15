{-|

Update the values of a list with their absolute values. The input and output portions will be handled automatically during grading. You only need to write a function with the recommended method signature.

Input Format

There are N integers, each on a separate line. These are the N elements of the input array.

Output Format

Output the absolute value of N integers, each on a separate line in the same input order.

Sample Input

2
-4
3
-1
23
-4
-54

Sample Output

2
4
3
1
23
4
54

Constraints



The list will have no more than 100 integers. 
Each integer, X, in the list: -100 <= X <= 100.

Recommended Method Signature

Number Of Parameters: 1
Parameters: [list]
Returns: List or Vector

-}

-- Enter your code here. Read input from STDIN. Print output to STDOUT
f arr = [abs x | x <- arr]

-- This section handles the Input/Output and can be used as it is. Do not modify it.
main = do
	inputdata <- getContents
	mapM_ putStrLn $ map show $ f $ map (read :: String -> Int) $ lines inputdata