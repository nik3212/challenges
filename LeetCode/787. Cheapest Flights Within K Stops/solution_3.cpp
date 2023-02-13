/*

787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dp(n, 0x3f3f3f);
        std::vector<int> s(n, 0);

        dp[src] = 0;

        for (int i = 0; i <= k; ++i) {
            std::vector<int> t_dp(dp);
            for (auto &e: flights) {
                t_dp[e[1]] = std::min(t_dp[e[1]], dp[e[0]] + e[2]);
            }
            dp = t_dp;
        }

        return dp[dst] == 0x3f3f3f ? -1 : dp[dst];
    }
};