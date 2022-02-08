/*

77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

*/

class Solution {
private:
    std::vector<std::vector<int>> res;

    void helper(int s, int n, int k, std::vector<int>& tmp) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        for (int i = s; i <= n; ++i) {
            tmp.push_back(i);
            helper(i + 1, n, k, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> tmp;
        helper(1, n, k, tmp);
        return res;
    }
};