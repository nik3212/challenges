/*

Min Sum Path in Matrix

Problem Description

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time. 

Input Format

First and only argument is an 2D integer array A of size M x N.

Output Format

Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).

*/

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    dp[0][0] = A[0][0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + A[i][0];
    }
    
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + A[0][j];
    } 

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
        }
    }

    return dp[n - 1][m - 1];
}
