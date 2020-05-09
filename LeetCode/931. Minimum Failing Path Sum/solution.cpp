/*

931. Minimum Falling Path Sum

Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.


Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12

Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

The falling path with the smallest sum is [1,4,7], so the answer is 12.

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        size_t n = v.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));

        for (size_t i = 0; i < n; ++i) {
            dp[0][i] = v[0][i];
        }

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                int left, right;
                left = right = std::numeric_limits<int>::max();

                if (j > 0) {
                    left = dp[i - 1][j - 1];
                }

                if (j < n - 1) {
                    right = dp[i - 1][j + 1];
                }

                dp[i][j] = v[i][j] + std::min(std::min(left, right), dp[i - 1][j]);
            }
        }

        int result = std::numeric_limits<int>::max();

        for (auto& item: dp[n - 1]) {
            result = std::min(result, item);
        }

        return result;
    }
};