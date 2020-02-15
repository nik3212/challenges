/*

70. Climbing Stairs.

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
    func climbStairs(_ n: Int) -> Int {
        if n < 3 {
            return n;
        }
        
        var f1 = 2
        var f2 = 1
        var current = 0
        
        for i in 3...n {
            current = f1 + f2
            f2 = f1
            f1 = current
        }
        
        return current
    }
}