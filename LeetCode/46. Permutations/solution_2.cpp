/*

46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

*/

class Solution {
private:
    void permute(std::vector<std::vector<int>>& res, std::vector<int> &curr, std::vector<int> &nums, int pos, std::set<int>& s) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (s.count(nums[i]) != 0) { continue; }
            s.insert(nums[i]);
            curr.push_back(nums[i]);
            permute(res, curr, nums, i, s);
            curr.pop_back();
            s.erase(nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> v;
        std::vector<int> curr;
        std::set<int> s;

        permute(v, curr, nums, 0, s);

        return v;
    }
};