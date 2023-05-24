/*

216. Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

*/

class Solution {
private:
    void generate(std::vector<std::vector<int>> &v, std::vector<int> &curr, int idx, int k, int n) {
        if (!k || !n) {
            if (!k && !n) {
                v.push_back(curr);
            }
            return;
        }

        for (int i = idx; i <= 9; i++) {
            if (n < i) { return; }

            curr.push_back(i);
            generate(v, curr, i + 1, k - 1, n - i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> res;
        std::vector<int> curr;

        generate(res, curr, 1, k, n);

        return res;
    }
};