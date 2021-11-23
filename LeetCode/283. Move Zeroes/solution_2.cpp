/*

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int last_element = 0, current = 0; current < nums.size(); ++current) {
            if (nums[current] != 0) {
                swap(nums[last_element++], nums[current]);
            }
        }
    }
};