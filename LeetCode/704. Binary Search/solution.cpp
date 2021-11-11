/*

704. Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

*/

class Solution {
    int binary_search(std::vector<int>& nums, int target, int left, int right) {
        if (right < left) {
            return -1;
        }

        int middle = (right + left) / 2;

        if (nums[middle] < target) {
            return binary_search(nums, target, middle + 1, right);
        } else if (nums[middle] > target) {
            return binary_search(nums, target, left, middle - 1);
        } else {
            return middle;
        }
     }
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size() - 1);
    }
};