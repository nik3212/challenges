/*

221. Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;

        std::vector<std::vector<int>>dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            res = std::max(res, dp[i][0]);
        }

        for (int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            res = std::max(res, dp[0][j]);
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (dp[i - 1][j] > 0 && dp[i][j - 1] > 0 && dp[i - 1][j - 1] > 0) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = std::min(dp[i][j - 1], std::min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                    }
                } else {
                    dp[i][j] = matrix[i][j] - '0';
                }
                res = std::max(res, dp[i][j]);
            }
        }

        return res * res;
    }
};