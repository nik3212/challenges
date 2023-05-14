/*

2685. Count the Number of Complete Components

You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

*/

class Solution {
private:
    std::vector<std::vector<int>> build_matrix(std::vector<std::vector<int>> &edges, int n) {
        std::vector<std::vector<int>> m(n);

        for (int i = 0; i < edges.size(); ++i) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        return m;
    }

    void dfs(std::vector<std::vector<int>> &m, std::vector<bool> &v, std::vector<int> &comps, int i) {
        v[i] = true;
 
        comps.push_back(i);

        for (auto k: m[i]) {
            if (!v[k]) {
                dfs(m, v, comps, k);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> matrix;
        std::vector<bool> visited(n, false);

        matrix = build_matrix(edges, n);

        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                std::vector<int> comp;

                dfs(matrix, visited, comp, i);

                int count = 0;

                for (int j = 0; j < comp.size(); ++j) {
                    if (matrix[comp[j]].size() >= comp.size() - 1) {
                        count++;
                    }

                    if (count == comp.size()) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};