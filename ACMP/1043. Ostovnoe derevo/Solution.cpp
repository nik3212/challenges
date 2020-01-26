/*

1043. Ostovnoe derevo

(Time limit: 2 sec. Memory limit: 16 MB Difficulty: 62%)

Требуется найти в связном неориентированном графе остовное дерево минимального веса.

Входные данные

Первая строка входного файла INPUT.TXT содержит два натуральных числа N и M – количество вершин и ребер графа соответственно (1 ≤ N ≤ 20 000, 0 ≤ M ≤ 100 000). Следующие M строк содержат описание ребер по одному на строке. Ребро номер i описывается тремя натуральными числами Bi, Ei и Wi – номера концов ребра и его вес соответственно (1 ≤ Bi, Ei ≤ N, 0 ≤ Wi ≤ 100 000).

Выходные данные

В выходной файл OUTPUT.TXT выведите целое число – вес минимального остовного дерева.

*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    explicit DSU(size_t size) {
        parent = std::vector<int>(size);
        rank = std::vector<int>(size);
    }

    void make_set(int x) {
        parent[x] = x;
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
                ++rank[a];
            }
        }
    }
};

class Graph {
private:
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    int v;
    int e;
public:
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
    }

    void add_edge(int v, int w, int k) {
        edges.push_back({ k, { v, w } });
    }

    int kruskal() {
        int weight = 0;

        std::sort(edges.begin(), edges.end());

        DSU dsu(v);

        for (size_t i = 0; i < v; ++i) {
            dsu.make_set(i);
        }

        std::vector<std::pair<int, std::pair<int, int>>>::iterator it;

        for (it = edges.begin(); it != edges.end(); ++it) {
            int u = it->second.first;
            int w = it->second.second;

            int set_u = dsu.find_set(u);
            int set_w = dsu.find_set(w);

            if (set_u != set_w) {
                weight += it->first;
                dsu.union_sets(set_u, set_w);
            }
        }

        return weight;
    }
};

int main() {
    size_t v, w;
    std::cin >> v >> w;

    Graph g(v + 1, w + 1);

    for (size_t j = 0; j < w; ++j) {
        int v, w, k;
        std::cin >> v >> w >> k;
        g.add_edge(v, w, k);
    }

    std::cout << g.kruskal() << std::endl;

    return 0;
}
