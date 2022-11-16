/*

300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int ans = -10001;

        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }

        return ans;
    }
};