/*

63. Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[i][0] == 1) { break; }
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[0][j] == 1) { break; }
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) { continue; }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};