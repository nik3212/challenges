/*

Cycle in Undirected Graph

Problem Description

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

*/

std::vector<std::vector<int>> build_matrix(int n, std::vector<std::vector<int>> &m) {
    std::vector<std::vector<int>> v(n, std::vector<int>());
    
    for (int i = 0; i < m.size(); ++i) {
        v[m[i][0]].push_back(m[i][1]);
        v[m[i][1]].push_back(m[i][0]);
    }

    return v;
}

void has_cycle(std::vector<std::vector<int>>& m, std::vector<bool> &visited, int v, int p, bool &res) {
    visited[v] = true;

    for (auto &u: m[v]) {
        if (!visited[u]) {
            has_cycle(m, visited, u, v, res);
        } else if (u != p) {
            res = true;
        }
    }
}

int Solution::solve(int A, vector<vector<int>> &B) {
    std::vector<std::vector<int>> m = build_matrix(A + 1, B);
    std::vector<bool> visited(A + 1, false);

    bool ans = false;
    for (int i = 1; i <= A; ++i) {
        if (!visited[i]) {
            has_cycle(m, visited, i, i - 1, ans);
        }
        if (ans) {
            return 1;
        }
    }

    return 0;
}