/*

46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

*/

class Solution {
private:
    std::vector<std::vector<int>> res;

    void helper(std::vector<int>& path, std::vector<bool>& visited, std::vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                helper(path, visited, nums);
                visited[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<bool> visited(nums.size(), false);
        std::vector<int> path;

        helper(path, visited, nums);

        return res;
    }
};