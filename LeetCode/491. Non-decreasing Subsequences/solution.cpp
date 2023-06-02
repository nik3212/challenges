/*

491. Non-decreasing Subsequences

Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

*/

class Solution {
private:
    std::set<std::vector<int>> s;

    void subs(std::vector<std::vector<int>> &res, std::vector<int> &curr, std::vector<int> &nums, int level, int prev) {
        if (curr.size() > 1 && s.count(curr) == 0) {
            res.push_back(curr);
            s.insert(curr);
        }

        if (level == nums.size()) {
            return;
        }

        for (int i = level; i < nums.size(); ++i) {
            if (prev > nums[i]) { continue; }

            curr.push_back(nums[i]);
            subs(res, curr, nums, i + 1, nums[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;
        subs(res, curr, nums, 0, -1000);
        return res;
    }
};