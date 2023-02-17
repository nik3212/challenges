/*

1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

*/

class Solution {
private:
    class DSU {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    public:
        DSU(int n) {
            parent = std::vector<int>(n, 0);
            rank = std::vector<int>(n, 0);

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
        }

        int find_set(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }

        void union_sets(int x, int y) {
            int a = find_set(x);
            int b = find_set(y);

            if (a != b) {
                if (rank[a] < rank[b]) {
                    std::swap(a, b);
                }

                parent[b] = parent[a];

                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }
    };
private:
    std::vector<std::pair<int, pair_ii>> matrix(std::vector<std::vector<int>> const &points) {
        int n = points.size();
        std::vector<std::pair<int, pair_ii>> m;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int w = abs(x) + abs(y);

                m.push_back({ w, { i, j } });
            }
        }

        return m;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        auto m = matrix(points);
        DSU dsu(points.size());

        std::sort(m.begin(), m.end());

        for (auto &e: m) {
            int a = dsu.find_set(e.second[0]);
            int b = dsu.find_set(e.second[1]);

            if (a != b) {
                res += e.first;
                dsu.union_sets(a, b);
            }
        }

        return res;
    }
};