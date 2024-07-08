/*

Coin Change

You are given coins of different denominations, represented by an array - coins of size n. 
You are also given a value - target. Find the different number of combinations that make up the amount target.
Assume that you have infinite number of each kind of coin.

*/

int numberOfCombinations(vector<int> &coins, int target) {
    std::sort(coins.begin(), coins.end());

    std::vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); ++i) {
        for (int j = coins[i]; j <= target; ++j) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[target];
}