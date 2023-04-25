/*

Path in Directed Graph

Problem Description

Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

*/

bool dfs(std::vector<std::vector<int>> &m, std::vector<bool> &visited, int v, int a) {
    if (v == a) {
        return true;
    }

    visited[v] = true;
    
    for (auto &u: m[v]) {
        if (!visited[u]) {
            if (dfs(m, visited, u, a)) {
                return true;
            }
        }
    }
    
    return false;
}

std::vector<std::vector<int>> build_matrix(int n, std::vector<std::vector<int>> &m) {
    std::vector<std::vector<int>> v(n, std::vector<int>());
    
    for (int i = 0; i < m.size(); ++i) {
        v[m[i][0]].push_back(m[i][1]);
    }

    return v;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    std::vector<std::vector<int>> m = build_matrix(A + 1, B);
    std::vector<bool> visited(A + 1, false);
    
    return dfs(m, visited, 1, A);
}
