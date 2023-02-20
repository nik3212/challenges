/*

2395. Find Subarrays With Equal Sum

Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.

Return true if these subarrays exist, and false otherwise.

A subarray is a contiguous non-empty sequence of elements within an array.

*/

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        std::set<int> s;

        for (int i = 0; i < nums.size() - 1; i++) {
            int v = nums[i] + nums[i + 1];
            if (s.find(v) != s.end()) {
                return true;
            }
            s.insert(v);
        }

        return false;
    }
};