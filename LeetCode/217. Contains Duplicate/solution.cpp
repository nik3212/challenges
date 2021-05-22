/*

217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> set(nums.begin(), nums.end());
        return set.size() != nums.size();
    }
};