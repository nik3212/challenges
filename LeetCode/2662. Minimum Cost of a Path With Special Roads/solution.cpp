/*

2662. Minimum Cost of a Path With Special Roads

You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

*/

using i_pair = std::pair<int, std::pair<int, int>>;

class Solution { 
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        std::set<std::pair<int, int>> nodes;

        nodes.insert({ start[0], start[1] });
        nodes.insert({ target[0], target[1] });

        for (auto &sr: specialRoads) {
            nodes.insert({ sr[0], sr[1] });
            nodes.insert({ sr[2], sr[3] });
        }

        std::map<std::pair<int, int>, int> m;
        std::vector<std::pair<int, int>> v_nodes;

        int index = 0;
        for (auto &n: nodes) {
            v_nodes.push_back(n);
            m[n] = index;
            index++;
        }

        int n = v_nodes.size();
        std::vector<std::vector<int>> adj(n, std::vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                adj[i][j] = abs(v_nodes[i].first - v_nodes[j].first) + abs(v_nodes[i].second - v_nodes[j].second);
            }
        }

        for (auto &sr: specialRoads) {
            int i = m[{ sr[0], sr[1] }];
            int j = m[{ sr[2], sr[3] }];

            adj[i][j] = std::min(adj[i][j], sr[4]);
        }

        std::priority_queue<i_pair, std::vector<i_pair>, std::greater<i_pair>> q;
        std::vector<bool> visited(n);

        q.push({ 0, { start[0], start[1] }});

        while (!q.empty()) {
            auto sr = q.top();
            q.pop();

            if (sr.second.first == target[0] && sr.second.second == target[1]) {
                return sr.first;
            }

            int v = m[sr.second];
            if (visited[v]) {
                continue;
            }

            visited[v] = true;

            for (int i = 0; i < n; ++i) {
                if (visited[i]) {
                    continue;
                }

                int w = sr.first + adj[v][i];
                q.push({ w, { v_nodes[i].first, v_nodes[i].second } });
            }
        }

        return 0;
    }
};