/*

Best Time to Buy and Sell Stocks II

You are given an array prices where prices[i] denotes the price of a stock on the ith day. You want to maximize the profit by buying a stock and then selling it at a higher price.

Suppose you can do as many transactions as you want, what is the maximum profit that you can make?

Note:

* Return 0 if you cannot make a profit.
* You cannot buy/hold more than 1 stock at a time.
* You need to sell a stock before buying again.
* You can sell a stock and buy it again on the same day.

*/

int maxProfit(vector<int> &prices) {
    int min_profit = prices[0];
	int res = 0;

	for (int i = 1; i < prices.size(); ++i) {
		if (min_profit > prices[i]) {
			min_profit = prices[i];
		} else {
			res += prices[i] - min_profit;
			min_profit = prices[i];
		}
	}
	
	return res;
}