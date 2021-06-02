/*

1631. Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

*/

class Solution {
public:
    using iPair = std::pair<int, std::pair<int, int>>;

    bool is_valid(int x, int y, int n, int m) {
        return (x >= 0) && (y >= 0) && (x < n) && (y < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        std::vector<std::pair<int, int>> destinations = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, INT_MAX));
        std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> queue;

        queue.push({ 0, { 0, 0 } });
        dp[0][0] = 0;

        std::vector<std::vector<bool>> visisted(n, std::vector<bool>(m, false));

        while (!queue.empty()) {
            auto val = queue.top();
            queue.pop();

            int w = val.first;

            int x = val.second.first;
            int y = val.second.second;

            if (visisted[x][y]) {
                continue;
            }

            visisted[x][y] = true;

            for (auto dest: destinations) {
                int new_x = x + dest.first;
                int new_y = y + dest.second;

                if (is_valid(new_x, new_y, n, m)) {
                    int effort = max(dp[x][y], abs(heights[x][y] - heights[new_x][new_y]));
                    if (dp[new_x][new_y] > effort) {
                        dp[new_x][new_y] = effort;
                        queue.push({ effort, { new_x, new_y } });
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};