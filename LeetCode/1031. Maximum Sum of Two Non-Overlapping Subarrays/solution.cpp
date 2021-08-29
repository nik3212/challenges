/*

1031. Maximum Sum of Two Non-Overlapping Subarrays

Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

A subarray is a contiguous part of an array.

*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i - 1];
        }

        int l, r, res;

        l = nums[firstLen - 1];
        r = nums[secondLen - 1];
        res = nums[firstLen + secondLen - 1];
        
        for (size_t i = firstLen + secondLen; i < nums.size(); ++i) {
            l = max(l, nums[i - secondLen] - nums[i - firstLen - secondLen]);
            r = max(r, nums[i - firstLen] - nums[i - firstLen - secondLen]);
            res = max(res, max(l + nums[i] - nums[i - secondLen], r + nums[i] - nums[i - firstLen]));
        }

        return res;
    }
};