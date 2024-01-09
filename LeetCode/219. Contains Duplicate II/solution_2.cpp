/*

219. Contains Duplicate II

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) { return false; }

        std::set<int> m;

        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(nums[i])) { return true; }

            if (i >= k) { m.erase(m.find(nums[i - k])); }

            m.insert(nums[i]);
        }

        return false;
    }
};