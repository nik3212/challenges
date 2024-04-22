/*

5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) {
            return s;
        }

        int len = s.size();

        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, 0));

        int start = 0;
        int p_len = 1;

        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                p_len = 2;
            }
        }

        for (int j = 2; j < len; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                }

                if (dp[i][j] && p_len < j - i + 1) {
                    p_len = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, p_len);
    }
};