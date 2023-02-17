/*

1514. Path with Maximum Probability

You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

*/

using pair_id = std::pair<int, double>;
using pair_di = std::pair<double, int>;

class Solution {
private:
    std::vector<std::vector<pair_id>> build_matrix(std::vector<std::vector<int>> const &e, std::vector<double> const &w, int n) {
        std::vector<std::vector<pair_id>> m(n);

        for (int i = 0; i < e.size(); ++i) {
            m[e[i][0]].push_back({ e[i][1], w[i] });
            m[e[i][1]].push_back({ e[i][0], w[i] });
        }

        return m;
    }

    double d(std::vector<std::vector<pair_id>> const &m, int n, int s, int end) {
        std::vector<double> dp(n, 0);
        std::priority_queue<pair_di, std::vector<pair_di>, std::less<pair_di>> q;

        q.push({ 1, s });
        dp[s] = 1;

        while (!q.empty()) {
            pair_di p = q.top();
            q.pop();

            double dst = p.first;
            int e = p.second;

            for (auto &[u, w]: m[e]) {
                if (w * dp[e] > dp[u]) {
                    dp[u] = (double) dp[e] * w;
                    q.push({ dp[u], u });
                }
            }
        }

        return dp[end];
    }
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        auto m = build_matrix(edges, succProb, n);
        auto v = d(m, n, start, end);
        return v;
    }
};