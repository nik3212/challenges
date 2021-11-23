/*

283. Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_element = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[last_element++] = nums[i];
            }
        }

        for (int i = last_element; i < n; ++i) {
            nums[i] = 0;
        }
    }
};