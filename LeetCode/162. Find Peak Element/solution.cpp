/*

162. Find Peak Element

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (nums[m] > nums[m + 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};