/*

The directed unweighted graph is given. Sort topologically its vertices.

Input

The first line contains the number of vertices n (1 ≤ n ≤ 100000) and the number of edges m (1 ≤ m ≤ 100000) in a graph. Each of the next m lines describes the edge of the graph - two numbers, the initial and final vertex.

Output

Sort the graph topologically and print its sequence of vertices. If its impossible to sort graph topologically, print -1.

*/

#include <iostream>
#include <vector>
#include <algorithm>

enum Color { white = 0, grey, black };

bool is_cycle_graph(size_t v, std::vector<std::vector<size_t>>& g, std::vector<Color>& colors) {
    colors[v] = grey;

    for (size_t i = 0; i < g[v].size(); ++i) {
        size_t to = g[v][i];

        if (colors[to] == white) {
            if (is_cycle_graph(to, g, colors)) {
                return true;
            }
        } else if (colors[to] == grey) {
            return true;
        }
    }

    colors[v] = black;

    return false;
}

void dfs(size_t v, std::vector<std::vector<size_t>>& g, std::vector<bool>& used, std::vector<size_t>& order) {
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i) {
        size_t to = g[v][i];

        if (!used[to]) {
            dfs(to, g, used, order);
        }
    }

    order.push_back(v + 1);
}

void topological_sort(size_t n, std::vector<std::vector<size_t>>& g, std::vector<bool>& used, std::vector<size_t>& order) {
    for (size_t i = 0; i < n; ++i) {
        used[i] = false;
    }

    for (size_t i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i, g, used, order);
        }
    }

    std::reverse(order.begin(), order.end());
}

int main() {
    std::vector<std::vector<size_t>> g;

    size_t n, m;
    std::cin >> n >> m;

    g.assign(n, std::vector<size_t>());

    for (size_t i = 0; i < m; ++i) {
        size_t x, y;
        std::cin >> x >> y;

        g[x - 1].push_back(y - 1);
    }

    bool is_cycle = false;
    std::vector<Color> colors(n, white);

    for (size_t i = 0; i < n; ++i) {
        if (is_cycle) { break; }
        is_cycle = is_cycle_graph(i, g, colors);
    }

    if (is_cycle) {
        std::cout << "-1" << std::endl;
    } else {
        std::vector<bool> used(n);
        std::vector<size_t> order;
        topological_sort(n, g, used, order);

        for (auto& i: order) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
