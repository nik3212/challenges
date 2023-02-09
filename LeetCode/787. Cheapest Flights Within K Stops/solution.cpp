/*

787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

*/

using int_pair = std::pair<int, int>;

class Solution {
private:
    std::vector<std::vector<int_pair>> build_matrix(vector<vector<int>> const &flights, int n) {
        std::vector<std::vector<int_pair>> v(n, std::vector<int_pair>());

        for (int i = 0; i < flights.size(); ++i) {
            std::vector<int> f = flights[i];
            v[f[0]].push_back({ f[2], f[1] });
        }

        return v;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> stops(n, 0x3f3f3f);
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> q;

        auto m = build_matrix(flights, n);

        q.push({ 0, src, 0 });

        while (!q.empty()) {
            auto p = q.top();
            q.pop();

            int d = p[0];
            int s = p[1];
            int l = p[2];

            if (l > k + 1 || l > stops[s]) {
                continue;
            }

            stops[s] = l;

            if (s == dst) {
                return d;
            }

            for (auto &[distance, vertex]: m[s]) {
                q.push({ d + distance, vertex, l + 1 });
            }
        }

        return -1;
    }
};