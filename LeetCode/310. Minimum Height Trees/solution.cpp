/*

310. Minimum Height Trees

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

*/

class Solution {
private:
    std::vector<std::set<int>> build_matrix(int n, vector<std::vector<int>>& edges) {
        std::vector<std::set<int>> m = std::vector<std::set<int>>(n, std::set<int>());

        for (int i = 0; i < edges.size(); ++i) {
            int x = edges[i][0];
            int y = edges[i][1];

            m[x].insert(y);
            m[y].insert(x);
        }

        return m;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<std::vector<int>>& edges) {
        if (n < 2) {
            std::vector<int> r;
            for (int i = 0; i < n; ++i) {
                r.push_back(i);
            }
            return r;
        }

        auto matrix = build_matrix(n, edges);

        std::vector<int> leaves;

        for (int i = 0; i < n; ++i) {
            if (matrix[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        int nodes = n;

        while (nodes > 2) {
            std::vector<int> new_leaves;

            nodes -= leaves.size();

            for (auto &e: leaves) {
                int p = *matrix[e].begin(); // parent
                matrix[p].erase(e);

                if (matrix[p].size() == 1) {
                    new_leaves.push_back(p);
                }
            }

            leaves = new_leaves;
        }

        return leaves;
    }
};