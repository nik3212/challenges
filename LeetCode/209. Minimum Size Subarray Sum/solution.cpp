/*

209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

*/

/*

Time Complexity: O(N)
Space Complexity: O(1)

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0;
        int result = INT_MAX;
        int current = 0;

        for (int i = 0; i < nums.size(); ++i) {
            current += nums[i];

            while (current >= target) {
                result = min(result, i - j + 1);
                current -= nums[j++];
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};