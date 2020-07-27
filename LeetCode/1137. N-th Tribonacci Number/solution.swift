/*

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

*/

class Solution {
    func tribonacci(_ n: Int) -> Int {
        if n == 0 { return 0 }
        if n < 3 { return 1 }
        
        var a = 0
        var b = 1
        var c = 1
        var d = 0
        
        for i in 3...n {
            d = a + b + c
            a = b
            b = c
            c = d
        }
        
        return c
    }
}