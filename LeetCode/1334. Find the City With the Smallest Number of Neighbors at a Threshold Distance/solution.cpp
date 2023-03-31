/*

1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

*/

class Solution {
private:
    int INF = 0x3f3f3f;

    std::vector<std::vector<int>> build_matrix(std::vector<std::vector<int>> const &m, int n) {
        std::vector<std::vector<int>> d(n, std::vector<int>(n, INF));

        for (int i = 0; i < m.size(); ++i) {
            int v = m[i][0];
            int u = m[i][1];
            int w = m[i][2];

            d[v][u] = w;
            d[u][v] = w;
        }

        return d;
    }

    void floyd(std::vector<std::vector<int>> &m) {
        int n = m.size();

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (m[k][j] == INF || m[i][k] == INF) { continue; }
                    m[i][j] = std::min(m[i][j], m[k][j] + m[i][k]);
                }
            }
        }
    }

    int get_city(std::vector<std::vector<int>> &m, int t, int n) {
        int res = n;
        int city = -1;

        for (int i = 0; i < n; ++i) {
            int curr = 0;

            for (int j = 0; j < n; ++j) {
                if (i == j) { continue; }
                if (m[i][j] <= t) {
                    curr++;
                }
            }

            if (curr <= res) {
                res = curr;
                city = i;
            }
        }

        return city;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        auto m = build_matrix(edges, n);
        floyd(m);
        return get_city(m, distanceThreshold, n);
    }
};