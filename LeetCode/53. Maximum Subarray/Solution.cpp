/*

53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6

Explanation: [4,-1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        
        return ans;
     }
};