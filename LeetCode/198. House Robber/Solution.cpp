/*

198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.

*/

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t size = nums.size();
        
        if (size == 0) { return 0; }
        else if (size < 3) { return *(std::max_element(nums.begin(), nums.end())); }
        
        std::vector<int> dp(size);
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        
        for (size_t i = 3; i < size; ++i) {
            dp[i] = std::max(dp[i - 2], dp[i - 3]) + nums[i];
        }
        
        return std::max(dp[size - 1], dp[size - 2]);
    }
};