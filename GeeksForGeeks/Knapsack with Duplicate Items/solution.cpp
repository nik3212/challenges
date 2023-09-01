/*

Knapsack with Duplicate Items

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int n = N;
        int m = W;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                
                if (wt[i - 1] <= j) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - wt[i - 1]] + val[i - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};