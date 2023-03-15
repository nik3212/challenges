/*

1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

*/

class Solution {
private:
    class DSU {
    private:
        std::vector<int> parent;
        std::vector<int> rank;
    public:
        DSU(int size) {
            parent = std::vector<int>(size);
            rank = std::vector<int>(size, 0);

            for (int i = 0; i < size; ++i) {
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

                if (a == b) {
                    rank[a]++;
                }
            }
        }

        int find_set(int x) {
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find_set(parent[x]);
        }
    };
private:
    int count = 0;

    void make_connections(std::vector<std::vector<int>> const &v, DSU &dsu) {
        for (int i = 0; i < v.size(); ++i) {
            int x = v[i][0];
            int y = v[i][1];

            int x_set = dsu.find_set(x);
            int y_set = dsu.find_set(y);

            if (x_set != y_set) {
                dsu.union_sets(x, y);
            } else {
                count++;
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        make_connections(connections, dsu);
        int res = 0;

        for (int i = 0; i < n - 1; ++i) {
            int x = i;
            int y = i + 1;

            int x_set = dsu.find_set(x);
            int y_set = dsu.find_set(y);

            if (x_set != y_set) {
                dsu.union_sets(x, y);
                count--;
                res++;
            }
        }

        return count >= 0 ? res : -1;
    }
};