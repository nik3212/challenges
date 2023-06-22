/*

1267. Count Servers that Communicate

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

*/

class Solution {
private:
    class dsu {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    public:
        dsu(int n) {
            rank = std::vector<int>(n, 0);
            parent = std::vector<int>(n, 0);

            for (int i = 0; i < n; ++i) {
                parent[i] = i;
            }
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
                    rank[a]++;
                }
            }
        }

        int find_set(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }
    };
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<int> v(n + m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    v[i]++;
                    v[j + n]++;
                }
            }
        }

        dsu d(n + m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    d.union_sets(i, j + n);
                }
            }
        }

        std::map<int, int> mp;

        for (int i = 0; i < n + m; ++i) {
            int k = d.find_set(i);
            mp[k] += v[i];
        }

        int ans = 0;

        for (auto i: mp) {
            if (i.second > 2) {
                ans += (i.second / 2);
            }
        }

        return ans;
    }
};