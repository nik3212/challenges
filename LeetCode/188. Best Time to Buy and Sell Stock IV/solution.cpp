/*

188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(prices.size()));

        for (int i = 1; i < dp.size(); ++i) {
            int diff = -prices[0];

            for (int j = 1; j < dp[0].size(); ++j) {
                diff = max(diff, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], prices[j] + diff);
            }
        }

        return dp[k][prices.size() - 1];
    }
};