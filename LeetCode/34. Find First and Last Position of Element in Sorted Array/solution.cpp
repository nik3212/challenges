/*

34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

*/

class Solution {
private:
    int left_binary_search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int res = -1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) {
                res = m;
                r -= 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }

    int right_binary_search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int res = -1;

        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] == target) {
                res = m;
                l += 1;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = left_binary_search(nums, target);
        int r = right_binary_search(nums, target);

        std::vector<int> res = { l, r };

        return res;
    }
};