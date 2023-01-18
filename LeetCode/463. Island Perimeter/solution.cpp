/*

463. Island Perimeter

You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

*/

class Solution {
private:
    int dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0 || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 1;
        }

        if (grid[i][j] == -1) {
            return 0;
        }

        grid[i][j] = -1;

        return dfs(grid, i - 1, j) + dfs(grid, i, j - 1) + dfs(grid, i + 1, j) + dfs(grid, i, j + 1);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    res = dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};