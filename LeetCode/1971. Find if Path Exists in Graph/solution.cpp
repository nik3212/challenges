/*

1971. Find if Path Exists in Graph

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

*/

class Solution {
private:
    class dsu {
    private:
        std::vector<int> parent;
        std::vector<int> rank;

    public:
        dsu(int n) {
            rank = std::vector<int>(n, 0);

            for (int i = 0; i < n; ++i) {
                parent.push_back(i);
            }
        }

        int find_set(int x) {
            if (x == parent[x]) {
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

                parent[b] = a;

                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }
    };
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        dsu dsu(n);

        for (auto &e: edges) {
            dsu.union_sets(e[0], e[1]);
        }

        int a = dsu.find_set(source);
        int b = dsu.find_set(destination);

        return a == b;
    }
};