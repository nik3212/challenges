/*

Decode Ways

A message containing letters from 'A' to 'Z' is being encoded into numbers using the following encoding:

'A' -> 1
'B' -> 2
.
.
.
'Y' -> 25
'Z' -> 26

Given an encoded string, find the number of ways it can be decoded.

The total number of ways to decode can be larger than the largest 32 bit number. Return your answer with module 10^9 + 7.

*/

int numDecodings(std::string s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }

    int n = s.size();
    std::vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (s[i - 1] > '0') {
            dp[i] = dp[i - 1];
        }

        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000007;
        }
    }

    return dp[n];
}