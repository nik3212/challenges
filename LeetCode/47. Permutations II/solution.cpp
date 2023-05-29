/*

47. Permutations II

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

*/

class Solution {
    void permute(
        std::vector<std::vector<int>> &res,
        std::vector<int> &curr, 
        std::vector<int> &nums, 
        std::vector<bool> &visited,
        int n
    ) {
        if (curr.size() == n) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i] || (i > 0 && nums[i - 1] == nums[i] && !visited[i - 1])) { continue; }
 
            visited[i] = true;
            curr.push_back(nums[i]);

            permute(res, curr, nums, visited, n);

            curr.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> v;
        std::vector<int> curr;
        std::vector<bool> visited(nums.size(), false);

        permute(v, curr, nums, visited, nums.size());

        return v;
    }
};