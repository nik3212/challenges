/*

169. Majority Element

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (count == 0) {
                res = nums[i];
            }

            res == nums[i] ? count++ : count--;
        }

        return res;
    }
};