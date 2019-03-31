{-|

Print "Hello World" N amount of times. The input portion will be handled automatically. You need to write a function with the recommended method signature.

Input Format

A single line of input containing integer N, the number of times to print "Hello World".

Output Format

Output N lines, each containing "Hello World".

Constraints

0 <= N <= 50

Sample Input

4

Sample Output

Hello World
Hello World
Hello World
Hello World

Recommended Method Signature

Number Of Parameters: 1
Parameters: [n]
Returns: nil

For Hackers Using Clojure

This will be the outline of your function body (fill up the blank portion marked by underscores):

 (fn[n]___________________________)

For Hackers Using Scala

This will be the outline of your function body (fill up the blank portion marked by underscores):

 def f(n: Int) = ______________________

For Hackers Using Haskell

This will be the outline of your function body (fill up the blank portion marked by underscores):

 hello_worlds n = ______________________
 
For Hackers Using other Languages

You have to read input from standard input and write output to standard output. Please follow the input/output format mentioned above.

NOTE: You only need to submit the code above, after filling in the blanks appropriately. The input and output section will be handled by us. The focus is on writing the correct function.

-}

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

helloWorlds 1 = putStrLn "Hello World"
helloWorlds n = do
        putStrLn "Hello World" 
        helloWorlds (n - 1)

main :: IO()
main = do
    n <- readLn :: IO Int
    helloWorlds(n)
    -- Print "Hello World" on a new line 'n' times.
