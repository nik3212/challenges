/*

172. Factorial Trailing Zeroes

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

*/

class Solution {
public:
    int trailingZeroes(int n) {
        int z = 0;

        while (n) {
            z += n /= 5;
        }

        return z;
    }
};