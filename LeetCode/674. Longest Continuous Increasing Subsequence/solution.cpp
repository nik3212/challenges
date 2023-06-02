/*

674. Longest Continuous Increasing Subsequence

Given an unsorted array of integers nums, return the length of the longest continuous increasing subsequence (i.e. subarray). The subsequence must be strictly increasing.

A continuous increasing subsequence is defined by two indices l and r (l < r) such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].

*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int res = 0;
        int last = 0;

        for (int i = 0; i < v.size(); ++i) {
            if (i > 0 && v[i - 1] >= v[i]) { last = i; }
            res = std::max(res, i - last + 1);
        }
        
        return res;
    }
};