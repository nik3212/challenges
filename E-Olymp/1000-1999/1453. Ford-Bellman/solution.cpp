/*

1453. Ford-Bellman

Given a directed graph, that can contain multiple edges and loops. Each edge has a weight that is expressed by a number (possibly negative). It is guaranteed that there are no cycles of negative weight.

Calculate the length of the shortest paths from the vertex number 1 to all other vertices.

Input

First the number of vertices n (1 ≤ n ≤ 100) is given. It is followed by the number of edges m (0 ≤ m ≤ 10000). Next m triples describe the edges: beginning of the edge, the end of the edge and its weight (an integer from -100 to 100).

Output

Print n numbers - the distance from the vertex number 1 to all other vertices of the graph. If the path to the corresponding vertex does not exist, instead of the path length print the number 30000.

*/

#include <vector>
#include <iostream>

const int INF = 0x3f3f3f;

struct Edge {
    int a;
    int b;
    int cost;

    Edge(int a, int b, int cost): a(a), b(b), cost(cost) { }
};

std::vector<Edge> edges;

std::vector<int> bellman_ford(int n, int m, int source, const std::vector<Edge>& e) {
    std::vector<int> dp(n, INF);

    dp[source] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dp[e[j].a] < INF && dp[e[j].b] > dp[e[j].a] + e[j].cost) {
                dp[e[j].b] = dp[e[j].a] + e[j].cost;
            }
        }
    }

    return dp;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        Edge edge(a - 1, b - 1, w);
        edges.push_back(edge);
    }

    auto dp = bellman_ford(n, m, 0, edges);

    for (auto i: dp) {
        std::cout << ((i == INF) ? 30000 : i) << " ";
    }

    return 0;
}
