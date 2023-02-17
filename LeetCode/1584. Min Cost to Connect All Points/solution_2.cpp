/*

1584. Min Cost to Connect All Points

You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

*/

using pair_ii = std::pair<int, int>;

class Solution {
private:
    std::vector<std::vector<pair_ii>> matrix(std::vector<std::vector<int>> const &points) {
        int n = points.size();
        std::vector<std::vector<pair_ii>> m(n);

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int w = abs(x) + abs(y);

                m[i].push_back({ w, j });
                m[j].push_back({ w, i });
            }
        }

        return m;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        auto m = matrix(points);
        
        std::vector<bool> visited(points.size());
        std::priority_queue<pair_ii, std::vector<pair_ii>, std::greater<pair_ii>> q;

        q.push({ 0, 0 });

        while (!q.empty()) {
            pair_ii p = q.top();
            q.pop();

            int dst = p.first;
            int v = p.second;

            if (visited[v]) {
                continue;
            }
            
            res += dst;
            visited[v] = true;

            for (auto &[w, u]: m[v]) {
                if (!visited[u]) {
                    q.push({ w, u });
                }
            }
        }

        return res;
    }
};