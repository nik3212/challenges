/*

90. Subsets II

Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

*/

class Solution {
private:
    void subsets(std::vector<std::vector<int>> &res, std::vector<int> &curr, std::vector<int> const &nums, int level) {
        res.push_back(curr);

        for (int i = level; i < nums.size(); ++i) {
            if (i > level && nums[i] == nums[i - 1]) { continue; }

            curr.push_back(nums[i]);
            subsets(res, curr, nums, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> v;
        std::vector<int> curr;

        std::sort(nums.begin(), nums.end());

        subsets(v, curr, nums, 0);

        return v;
    }
};