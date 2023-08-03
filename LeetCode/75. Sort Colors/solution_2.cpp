/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;
        int m = 0;
        int e = nums.size() - 1;

        while (m <= e) {
            if (nums[m] == 0) {
                std::swap(nums[s++], nums[m++]);
            } else if (nums[m] == 1) {
                m++;
            } else {
                std::swap(nums[m], nums[e--]);
            }
        }
    }
};