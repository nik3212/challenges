/*

2829. Determine the Minimum Sum of a k-avoiding Array

You are given two integers, n and k.

An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.

Return the minimum possible sum of a k-avoiding array of length n.

*/

class Solution {
private:
    int sum(int a, int b) {
        return (a + b) * (b - a + 1) / 2;
    }
public:
    int minimumSum(int n, int k) {
        int m = k / 2;

        if (n <= m) {
            return sum(1, n);
        }

        return sum(1, m) + sum(k, k + (n - m - 1));
    }
};