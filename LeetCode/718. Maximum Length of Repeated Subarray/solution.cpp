/*

718. Maximum Length of Repeated Subarray

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

*/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + 1;
        int m = nums2.size() + 1;

        int ans = 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                if (ans < dp[i][j]) {
                    ans = dp[i][j];
                }
            }
        }

        return ans;
    }
};