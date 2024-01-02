/*

123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MAX;
        int b2 = INT_MAX;
        int s1 = 0;
        int s2 = 0;

        for (auto p: prices) {
            b1 = min(b1, p);
            s1 = max(s1, p - b1);

            b2 = min(b2, p - s1);
            s2 = max(s2, p - b2);
        }

        return s2;
    }
};