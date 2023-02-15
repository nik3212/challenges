/*

684. Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

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
    
        void union_sets(int x, int y) {
            int a = find_set(x);
            int b = find_set(y);

            if (a != b) {
                if (rank[a] < rank[b]) {
                    std::swap(rank[a], rank[b]);
                }

                parent[b] = parent[a];

                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }
    
        int find_set(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu = DSU(edges.size() + 1);

        for (auto &e: edges) {
            int a = dsu.find_set(e[0]);
            int b = dsu.find_set(e[1]);

            if (a == b) {
                return std::vector<int>({ e[0], e[1] });
            }

            dsu.union_sets(a, b);
        }

        return std::vector<int>();
    }
};