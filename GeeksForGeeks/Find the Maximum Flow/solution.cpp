/*

Find the Maximum Flow

Given a graph which represents a flow network with N vertices numbered 1 to N and M edges.Find the maximum flow from vertex numbered 1 to vertex numbered N.

In a flow network,every edge has a flow capacity and the maximum flow of a path can't exceed the flow-capacity of an edge in the path.

*/

using adj_matrix = std::vector<std::vector<int>>;

class Solution {
private:
    adj_matrix build_matrix(int n, int m, std::vector<std::vector<int>> &edges) {
        adj_matrix matrix(n, std::vector<int>(m, 0));
        
        for (auto edge: edges) {
            int i = edge[0];
            int j = edge[1];
            int w = edge[2];
            
            matrix[i][j] += w;
            matrix[j][i] += w;
        }
        
        return matrix;
    }

    bool bfs(adj_matrix &m, std::vector<int> &path, int s, int e, int V) {
        std::vector<int> visited(V, false);
        std::queue<int> q;
        q.push(s);

        visited[s] = true;
        path[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; ++v) {
                if (visited[v] == false && m[u][v] > 0) {
                    q.push(v);
                    path[v] = u;
                    visited[v] = true;
                }
            }
        }

        return visited[e];
    }

    int ford_fulkerson(adj_matrix &m, int s, int e, int n) {
        std::vector<int> path(n);
        
        int max_flow = 0;
        
        while (bfs(m, path, s, e, n)) {
            int flow = INT_MAX;
            
            for (int v = e; v != s; v = path[v]) {
                int u = path[v];
                flow = std::min(flow, m[u][v]);
            }

            for (int v = e; v != s; v = path[v]) {
                int u = path[v];
                m[u][v] -= flow;
                m[v][u] += flow;
            }
            
            max_flow += flow;
        }
        
        return max_flow;
    }
public:
    int findMaxFlow(int N,int M, vector<vector<int>> Edges) {
        auto matrix = build_matrix(N + 1, M + 1, Edges);
        return ford_fulkerson(matrix, 1, N, N + 1);
    }
};