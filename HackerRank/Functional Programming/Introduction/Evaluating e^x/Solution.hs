{-|

The series expansion of e^x is given by:

1 + x + x^2/2! + x^3/3! + x^4/4! + ...

Evaluate e^x for given values of x by using the above expansion for the first 10 terms.

Input Format

The first line contains an integer N, the number of test cases. 
N lines follow. Each line contains a value of x for which you need to output the value of e^x using the above series expansion. These input values have exactly 4 decimal places each.

Output Format

Output N lines, each containing the value of e^x, computed by your program.

Constraints

1 <= N <= 50
-20.00 <= x <= 20.00
 
Var, Val in Scala and def and defn in Clojure are blocked keywords. The challenge is to accomplish this without either mutable state or direct declaration of local variables.

Sample Input

4
20.0000
5.0000
0.5000
-0.5000

Sample Output

2423600.1887
143.6895
1.6487
0.6065

-}

{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe
import Text.Printf

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial(n - 1)

pow :: (Num a, Integral b) => a -> b -> a
pow _ 0 = 1
pow x n = x * pow x (n - 1)

exp' x = sum [pow x y / fromIntegral(factorial y) | y <- [0..9]]

main :: IO()
main = do
    n <- readLn :: IO Int

    forM_ [1..n] $ \n_itr -> do
        x <- readLn :: IO Double
        printf "%.4f\n" (exp' x)
