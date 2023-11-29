/*

647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(n + 1));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }

        for (int i = 3; i <= n; ++i) {
            for (int l = 0, r = l + i - 1; r < n; ++l, ++r) {
                dp[l][r] = (s[l] == s[r]) && dp[l + 1][r - 1];
            }
        }

        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int r = i; r < n; ++r) {
                res += dp[i][r];
            }
        }

        return res;
    }
};