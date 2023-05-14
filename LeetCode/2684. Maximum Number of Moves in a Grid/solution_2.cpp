/*

2684. Maximum Number of Moves in a Grid

You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

*/

class Solution {
private:
    int dfs(std::vector<std::vector<int>> &grid, int row, int col, int prev) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] <= prev) {
            return 0;
        }

        std::vector<int> dy = { -1, 0, 1 };

        int res = 0;

        int value = grid[row][col];
        grid[row][col] = 0;

        for (auto i: dy) {
            int new_row = row + i;
            int new_col = col + 1;

            res = max(res, dfs(grid, new_row, new_col, value) + 1);
        }

        return res;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(grid, i, 0, -1));
        }

        return res - 1;
    }
};