/*

743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/

using pair_ii = std::pair<int, int>;

class Solution {
private:
    std::vector<std::vector<pair_ii>> build_matrix(std::vector<std::vector<int>> const &v, int n) {
        std::vector<std::vector<pair_ii>> d(n + 1);

        for (auto &e: v) {
            d[e[0]].push_back({ e[1], e[2] });
        }

        return d;
    }

    std::vector<int> dijkstra(std::vector<std::vector<pair_ii>> const &m, int k, int &res) {
        std::vector<int> dp(m.size(), 0x3f3f3f);
        std::priority_queue<pair_ii, std::vector<pair_ii>, std::greater<pair_ii>> q;

        q.push({ 0, k });
        dp[k] = 0;

        while (!q.empty()) {
            res++;

            auto p = q.top();
            q.pop();

            int dst = p.first;
            int e = p.second;

            for (auto &[u, w]: m[e]) {
                if (w + dp[e] < dp[u]) {
                    dp[u] = dp[e] + w;
                    q.push({ dp[u], u });
                }
            }
        }

        return dp;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int t = 0;
        int res = -1;

        auto m = build_matrix(times, n);
        auto dp = dijkstra(m, k, t);

        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] != 0x3f3f3f) {
                res = std::max(res, dp[i]);
            }
        }

        if (res == 0) {
            return -1;
        }

        return (t == n - 1) ? -1 : res;
    }
};