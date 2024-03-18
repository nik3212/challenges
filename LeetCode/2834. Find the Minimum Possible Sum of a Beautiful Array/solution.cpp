/*

2834. Find the Minimum Possible Sum of a Beautiful Array

You are given positive integers n and target.

An array nums is beautiful if it meets the following conditions:

nums.length == n.
nums consists of pairwise distinct positive integers.
There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
Return the minimum possible sum that a beautiful array could have modulo 109 + 7.

*/

class Solution {
public:
    const int MOD=1e9+7;
    long long minimumPossibleSum(int n, int target) {
        long long mid = target >> 1;

        if(n <= mid) {
            return n * 1ll * (n + 1) / 2 % MOD;
        }


        long long ans = mid * (mid + 1) / 2;
        ans %= MOD;

        long long rem = n - mid;

        ans += target * rem + (rem * 1ll * (rem - 1) / 2);
        ans %= MOD;
                
        return ans;
    }
};