/*

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

*/

class Solution {
private:
    int dfs(vector<vector<int>>& grid, std::vector<std::vector<int>>& dp, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        grid[x][y] = -1;

        std::vector<int> x_val = { -1, 0, 0, 1 };
        std::vector<int> y_val = { 0, -1, 1, 0 };

        int ans = 0;
        
        for (int i = 0; i < 4; ++i) {
            int new_x = x + x_val[i];
            int new_y = y + y_val[i];

            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 1) {
                ans += 1 + dfs(grid, dp, new_x, new_y);
            }
        }

        dp[x][y] = ans;

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));

        int result = -1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    int ans = dfs(grid, dp, i, j);
                    result = max(result, ans);
                }
            }
        }

        return result + 1;
    }
};