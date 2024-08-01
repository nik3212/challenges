/*

1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

*/

class Solution {
public:
    int minInsertions(string A) {
        int n = A.size();
        std::string s = A;
        
        std::reverse(s.begin(), s.end());
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
        
        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == A[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};