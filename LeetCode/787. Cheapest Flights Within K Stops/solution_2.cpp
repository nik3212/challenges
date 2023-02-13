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
        std::queue<std::vector<int>> q;
        std::vector<int> distances(n, 0x3f3f3f);

        auto m = build_matrix(flights, n);

        q.push({ src, 0 });
        distances[src] = 0;

        int level = 0;

        while (level <= k && !q.empty()) {
            int size = q.size();

            while (size--) {
                auto item = q.front();
                q.pop();

                for (auto &[d, v]: m[item[0]]) {
                    if (item[1] + d >= distances[v]) {
                        continue;
                    }
                    distances[v] = item[1] + d;
                    q.push({ v, distances[v] });
                }
            }

            level++;
        }

        return distances[dst] == 0x3f3f3f ? -1 : distances[dst];
    }
};