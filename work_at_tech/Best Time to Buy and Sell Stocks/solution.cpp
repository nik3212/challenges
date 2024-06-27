/*

Best Time to Buy and Sell Stocks

You are given an array prices where prices[i] denotes the price of a stock on the ith day. You want to maximize the profit by buying a stock and then selling it at a higher price.

Suppose you can make a single buy and single sell at any date after you buy, what is the maximum profit that you can make?

Note: Return 0 if you cannot make a profit.

*/

int maxProfit(vector<int> &prices) {
	int min_price = prices[0];
	int res = 0;
	
	for (int i = 1; i < prices.size(); ++i) {
		if (prices[i] < min_price) {
			min_price = prices[i];
		} else {
			res = std::max(res, prices[i] - min_price);
		}
	}
	
	return res;
}