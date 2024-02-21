/*

220. Contains Duplicate III

You are given an integer array nums and two integers indexDiff and valueDiff.

Find a pair of indices (i, j) such that:

i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Return true if such pair exists or false otherwise.

*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;

        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }

            auto it = window.lower_bound((long)nums[i] - t);
            if (it != window.end() && *it <= (long)nums[i] + t) {
                return true;
            }

            window.insert(nums[i]);
        }

        return false;
    }
};