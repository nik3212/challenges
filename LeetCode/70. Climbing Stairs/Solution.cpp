/*

70. Climbing Stairs.

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

*/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        
        int f1 = 2;
        int f2 = 1;
        int current = 0;
        
        for (int i = 3; i <= n; ++i) {
            current = f1 + f2;
            f2 = f1;
            f1 = current;
        }
        
        return current;
    }
};