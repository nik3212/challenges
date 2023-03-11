/*

40. Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

*/

class Solution {
private:
    void combinations(std::vector<std::vector<int>> &res, std::vector<int> &curr, std::vector<int> const &candidates, int target, int level) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = level; i < candidates.size(); ++i) {
            if (candidates[i] > target) { break; }
            if (i > level && candidates[i] == candidates[i - 1]) { continue; }

            curr.push_back(candidates[i]);
            combinations(res, curr, candidates, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> v;
        std::vector<int> curr;

        std::sort(candidates.begin(), candidates.end());

        combinations(v, curr, candidates, target, 0);

        return v;
    }
};