/*

785. Is Graph Bipartite?

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

* There are no self-edges (graph[u] does not contain u).
* There are no parallel edges (graph[u] does not contain duplicate values).
* If v is in graph[u], then u is in graph[v] (the graph is undirected).
* The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

*/

class Solution {
private:
    std::vector<std::vector<int>> make_graph(std::vector<std::vector<int>> const &graph) {
        int n = graph.size();

        std::vector<std::vector<int>> g(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                g[i].push_back(graph[i][j]);
            }
        }

        return g;
    }

    int invert(int color) {
        return color == 1 ? 2 : 1;
    }

    void dfs(std::vector<std::vector<int>> const &g, std::vector<int> &colors, int v, int c, bool &res) {
        colors[v] = c;

        for (auto u: g[v]) {
            if (colors[u] == 0) {
                dfs(g, colors, u, invert(c), res);
            } else if (colors[u] == c) {
                res = false;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        auto m = make_graph(graph);
        bool res = true;
        std::vector<int> colors(graph.size(), 0);

        for (int i = 0; i < graph.size(); ++i) {
            if (colors[i] == 0) {
                dfs(m, colors, i, 1, res);
            }
            if (res == false) {
                break;
            }
        }

        return res;
    }
};