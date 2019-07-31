{-|

Filter a given array of integers and output only those values that are less than a specified value X. The output integers should be in the same sequence as they were in the input. You need to write a function with the recommended method signature for the languages mentioned below. For the rest of the languages, you have to write a complete code.

Input Format

The first line contains the delimiter X. 
The next B lines each contain an integer, which represents the elements of the list/array. You have to read the input to the End-Of-File.

Output Format

Print all the integers from the array that are less than the given upper limit X in value on separate lines. The sequence should be the same as it was in the original array.

Constraints

1 <= B <= 100
For any element, Y in the array, -100 <= Y <= 100  
-100 <= X <= 100

-}

f :: Int -> [Int] -> [Int]
f n arr = [num | num <- arr, num < n]

-- The Input/Output section. You do not need to change or modify this part
main = do 
    n <- readLn :: IO Int 
    inputdata <- getContents 
    let 
        numbers = map read (lines inputdata) :: [Int] 
    putStrLn . unlines $ (map show . f n) numbers