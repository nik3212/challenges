/*

2684. Maximum Number of Moves in a Grid

You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

*/

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
   
        for (int col = m - 2; col >= 0; --col) {
            for (int row = 0; row < n; ++row) {
                for (int k: { -1, 0, 1 }) {
                    int new_row = row + k;
                    int new_col = col + 1;

                    if (new_row >= 0 && new_row < n && grid[new_row][new_col] > grid[row][col]) {
                        dp[row][col] = max(dp[row][col], dp[new_row][new_col] + 1);
                    }
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, dp[i][0]);
        }
        
        return res;
    }
};