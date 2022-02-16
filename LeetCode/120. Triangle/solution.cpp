/*

120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        const size_t MAX_VALUE = 100000;

        int sum = MAX_VALUE;
        int n = triangle.size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, MAX_VALUE));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < triangle[i].size(); ++j) {
                int value = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = value; 
            }
        }

        for (auto item: dp[n - 1]) {
            sum = min(sum, item);
        }

        return sum;
    }
};