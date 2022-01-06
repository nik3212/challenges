/*

72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

*/

/*

Time Complexity: O((N + 1)(M + 1))
Space Complexity: O((N + 1)(M + 1))

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size() + 1;
        int m = word2.size() + 1;

        auto dp = std::vector<std::vector<int>>(n, std::vector<int>(m));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j < m; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                int m = word1[i - 1] == word2[j - 1] ? 0 : 1;

                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + m);
            }
        }

        return dp[n - 1][m - 1];
    }
};