/*

0-1 Knapsack

Problem Description

Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

*/

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int k = A.size();
    int w = C;

    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(w + 1, 0));

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= w; ++j) {
            dp[i][j] = dp[i - 1][j];
            
            if (B[i - 1] <= j) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - B[i - 1]] + A[i - 1]);
            }
        }
    }

    return dp[k][C];
}
