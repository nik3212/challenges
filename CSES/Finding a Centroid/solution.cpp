/*

Given a tree of n nodes, your task is to find a centroid, i.e., a node such that when it is appointed the root of the tree, each subtree has at most \lfloor n/2 \rfloor nodes.

Input

The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output

Print one integer: a centroid node. If there are several possibilities, you can choose any of them.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> subtree_size;

int get_subtree_size(int node, int parent = -1) {
    int &res = subtree_size[node];
    res = 1;

    for (int i: adj[node]) {
        if (i == parent) { continue; }
        res += get_subtree_size(i, node);
    }

    return res;
}

int centroid(int v, int n, int p = -1) {
    for (int i: adj[v]) {
        if (i == p) { continue; }
        if (subtree_size[i] * 2 > n) {
            return centroid(i, n, v);
        }
    }
    return v;
}

int main(int argc, const char * argv[]) {
    int n;

    std::cin >> n;
    
    adj = std::vector<std::vector<int>>(n);
    subtree_size = std::vector<int>(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;

        std::cin >> a >> b;

        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    get_subtree_size(0);
    std::cout << centroid(0, n) + 1;

    return 0;
}
