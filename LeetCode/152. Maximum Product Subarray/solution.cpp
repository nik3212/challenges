/*

152. Maximum Product Subarray

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t size = nums.size();
        int ans = nums[0];
        int max_n = ans;
        int min_n = ans;

        for (size_t i = 1; i < size; ++i) {
            if (nums[i] < 0) {
                std::swap(max_n, min_n);
            }
            max_n = std::max(max_n * nums[i], nums[i]);
            min_n = std::min(min_n * nums[i], nums[i]);
            ans = std::max(ans, max_n);
        }

        return ans;
    }
};