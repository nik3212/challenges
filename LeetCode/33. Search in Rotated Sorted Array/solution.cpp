/*

33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

*/

class Solution {
private:
    int binary_search(std::vector<int> &nums, int key, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == key) {
                return m;
            } else if (nums[m] < key) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;

        int l = 0;
        int r = n;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] > nums[n]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        int x = l;

        if (nums[n] < target) {
            l = 0;
            r = x;
        } else {
            l = x;
            r = n;
        }

        return binary_search(nums, target, l, r);
    }
};