{-|

Given a list, repeat each element in the list n amount of times. The input and output portions will be handled automatically by the grader. You need to write a function with the recommended method signature.

Input Format

The first line contains the integer S where S is the number of times you need to repeat the elements. 
The next X lines each contain an integer. These are the X elements in the array.

Output Format

Output each element of the original list S times, each on a separate line. You have to return the list/vector/array of S * X integers. The relative positions of the values should be the same as the original list provided in the input.

Constraints

0 <= X <= 10
1 <= S <= 100

-}

f :: Int -> [Int] -> [Int]
f n arr = [num | num <- arr , a <- [1..n]]

-- This part handles the Input and Output and can be used as it is. Do not modify this part.
main :: IO ()
main = getContents >>=
       mapM_ print. (\(n:arr) -> f n arr). map read. words