/*

78. Subsets

Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

*/

class Solution {
private:
    void subsets(std::vector<int> const &nums, std::vector<std::vector<int>> &res, std::vector<int> &curr, int level) {
        if (nums.size() < level) {
            return;
        }

        res.push_back(curr);

        for (int i = level; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            subsets(nums, res, curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;

        subsets(nums, res, curr, 0);

        return res;
    }
};