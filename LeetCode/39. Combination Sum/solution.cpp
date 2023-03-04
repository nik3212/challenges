/*

39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

*/

class Solution {
    void combinationSum(std::vector<int>& candidates, int target, std::vector<std::vector<int>> &res, std::vector<int> &curr, int sum, int pos) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(curr);
            return;
        }

        for (int i = pos; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            sum += candidates[i];
            combinationSum(candidates, target, res, curr, sum, i);
            curr.pop_back();
            sum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> v;
        std::vector<int> curr;

        combinationSum(candidates, target, v, curr, 0, 0);

        return v;
    }
};