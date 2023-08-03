/*

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

*/

class Solution {
private:
    void sort(std::vector<int> &nums) {
        bool is_sorted = true;

        while (is_sorted) {
            is_sorted = false;

            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] > nums[i + 1]) {
                    std::swap(nums[i], nums[i + 1]);
                    is_sorted = true;
                }
            }
        }
    }
public:
    void sortColors(vector<int>& nums) {
        sort(nums);
    }
};