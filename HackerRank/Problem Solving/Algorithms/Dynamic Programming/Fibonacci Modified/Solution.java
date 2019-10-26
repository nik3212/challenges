/*

We define a modified Fibonacci sequence using the following definition:

Given terms t_i and t_i+1 where i ∈ (1; ∞), term t_i+2 is computed using the following relation:

t_i+2 = t_i + (t_i+1)^2

For example, if t_1 = 0 and t_2 = 1,
* t3 = 0 + 1^2 = 1,
* t4 = 1 + 1 ^ 2 = 2,
* t5 = 1 + 2 ^ 2 = 5
* and so on.

Given three integers, t1, t2, and n, compute and print the n^th term of a modified Fibonacci sequence.

Function Description

Complete the fibonacciModified function in the editor below. It must return the n^th number in the sequence.

fibonacciModified has the following parameter(s):

* t1: an integer
* t2: an integer
* n: an integer

Note: The value of t_n may far exceed the range of a 64-bit integer. Many submission languages have libraries that can handle such large results but, for those that don't (e.g., C++), you will need to compensate for the size of the result.

Input Format

A single line of three space-separated integers describing the respective values of t1, t2, and n.

Constraints

0 <= t1, t2 <= 2
3 <= n <= 20
t_n may far exceed the range of a 64-bit integer.

Output Format

Print a single integer denoting the value of term t_n in the modified Fibonacci sequence where the first two terms are t1 and t2.

Sample Input

0 1 5

Sample Output

5

*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the fibonacciModified function below.
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t1 = in.nextInt();
        int t2 = in.nextInt();
        
        int n = in.nextInt();

        BigInteger f1 = BigInteger.valueOf(t1);
        BigInteger f2 = BigInteger.valueOf(t2);
        BigInteger tmp = null;

        for(int i = 0; i < n - 2; i++) {
            tmp = f1.add(f2.multiply(f2));
            
            f1 = f2;
            f2 = tmp;
        }

        System.out.println(f2);
    }
}
