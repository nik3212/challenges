/*

219. Contains Duplicate II

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> m;

        m[nums[0]] = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (m.count(nums[i]) > 0) {
                if (abs(m[nums[i]] - i) <= k) {
                    return true;
                }
            }

            m[nums[i]] = i;
        }

        return false;
    }
};