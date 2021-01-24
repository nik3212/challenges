/*

1043. Partition Array for Maximum Sum

Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:

Input: arr = [1], k = 1
Output: 1

*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        size_t n = arr.size();
        std::vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int max_element = 0;

            for (int j = i; j >= max(0, i - k + 1); --j) {
                max_element = max(max_element, arr[j]);
                dp[i] = max(dp[i], max_element * (i - j + 1) + (j > 0 ? dp[j - 1] : 0));
            }
        }

        return dp[n - 1];
    }
};