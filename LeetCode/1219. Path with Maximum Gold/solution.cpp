/*

1219. Path with Maximum Gold

In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

*/

class Solution {
private:
    int dfs(std::vector<std::vector<int>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }

        int val = grid[row][col];
        grid[row][col] = 0;

        int ans = val + max(
            {
                dfs(grid, row - 1, col),
                dfs(grid, row, col - 1),
                dfs(grid, row + 1, col),
                dfs(grid, row, col + 1)
            }
        );

        grid[row][col] = val;

        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                res = max(res, dfs(grid, i, j));
            }
        }

        return res;
    }
};