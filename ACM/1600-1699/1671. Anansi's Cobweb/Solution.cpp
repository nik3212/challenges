/*

1671. Anansi's Cobweb

Time limit: 1.0 second
Memory limit: 64 MB

Usatiy-Polosatiy XIII decided to destroy Anansi's home — his cobweb. The cobweb consists of N nodes, some of which are connected by threads. Let us say that two nodes belong to the same piece if it is possible to get from one node to the other by threads. Usatiy-Polosatiy has already decided which threads and in what order he would tear and now wants to know the number of pieces in cobweb after each of his actions.

Input

The first line contains integers N and M — the number of nodes and threads in the cobweb, respectively(2 ≤ N ≤ 100000; 1 ≤ M ≤ 100000). Each of the next M lines contains two different integers — the 1-based indices of nodes connected by current thread. The threads are numbered from 1 to M in the order of description. Next line contains an integer Q which denotes the quantity of threads Usatiy-Polosatiy wants to tear (1 ≤ Q ≤ M). The last line contains numbers of these threads — different integers separated by spaces.

Output

Output Q integers — the number of pieces in Anansi's cobweb after each of Usatiy-Polosatiy's action. Separate numbers with single spaces.

*/

#include <iostream>
#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    DSU(size_t size) {
        parent = std::vector<int>(size);
        rank = std::vector<int>(size);

        for (size_t i = 0; i < size; ++i) {
            parent[i] = i;
            rank[i] = 0;
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
                ++rank[a];
            }
        }
    }
};

int main() {
    int q;
    size_t n, m;
    std::cin >> n >> m;

    DSU dsu(n + 1);

    std::vector<int> u(m + 1);
    std::vector<int> v(m + 1);

    for (size_t i = 1; i <= m; ++i) {
        std::cin >> u[i] >> v[i];
    }

    std::cin >> q;
    std::vector<int> qu(q + 1);
    std::vector<bool> mark(m + 1);

    for (size_t i = 1; i <= q; ++i) {
        std::cin >> qu[i];
        mark[qu[i]] = true;
    }

    for (size_t i = 1; i <= m; ++i) {
        if (!mark[i]) {
            dsu.union_sets(v[i], u[i]);
        }
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (dsu.find_set(i) == i) {
            count++;
        }
    }

    std::vector<int> ans(q + 1);

    for (size_t i = q; i > 0; --i) {
        ans[i] = count;

        if (dsu.find_set(u[qu[i]]) != dsu.find_set(v[qu[i]])) {
            count--;
        }
        dsu.union_sets(u[qu[i]], v[qu[i]]);
    }

    for (int i = 1; i <= q; ++i) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
