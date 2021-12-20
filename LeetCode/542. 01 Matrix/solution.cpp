/*

542. 01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        std::vector<std::vector<int>> dist = std::vector<std::vector<int>>(n, std::vector<int>(m, INT_MAX - 10001));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != 0) {
                    if (i > 0) {
                        dist[i][j] = min(dist[i - 1][j] + 1, dist[i][j]);
                    }
                    if (j > 0) {
                        dist[i][j] = min(dist[i][j - 1] + 1, dist[i][j]);
                    }
                } else {
                    dist[i][j] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i < n - 1) {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }
                if (j < m - 1) {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }

        return dist;
    }
};