/*

200. Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

*/

class Solution {
private:
    int dfs(std::vector<std::vector<char>> &grid, std::vector<std::vector<bool>>& v, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return 0;
        }

        if (v[i][j]) {
            return 0;
        }

        v[i][j] = true;

        int t = dfs(grid, v, i - 1, j);
        int b = dfs(grid, v, i + 1, j);
        int l = dfs(grid, v, i, j - 1);
        int r = dfs(grid, v, i, j + 1);

        return 1 + t + b + l + r;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        std::vector<std::vector<bool>> v(n, std::vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(grid, v, i, j) > 0) {
                    res++;
                }
            }
        }

        return res;
    }
};