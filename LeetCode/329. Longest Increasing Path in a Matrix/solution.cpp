/*

329. Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

*/

class Solution {
    int dfs(vector<vector<int>>& matrix, int i, int j, int p, std::vector<std::vector<int>> &dp) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || p >= matrix[i][j]) {
            return 0;
        }

        if (dp[i][j]) {
            return dp[i][j];
        }

        int val = matrix[i][j];

        int t = dfs(matrix, i - 1, j, val, dp);
        int l = dfs(matrix, i, j - 1, val, dp);
        int r = dfs(matrix, i, j + 1, val, dp);
        int b = dfs(matrix, i + 1, j, val, dp);

        return dp[i][j] = 1 + max({t, l, r, b});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                r = max(r, dfs(matrix, i, j, -1, dp));
            }
        }

        return r;
    }
};