/*

Edit Distance

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format:

Return an integer, representing the minimum number of steps required.

Constraints:

1 <= length(A), length(B) <= 450

*/

int Solution::minDistance(string A, string B) {
    int n = A.size() + 1;
    int m = B.size() + 1;

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    for (int i = 1; i < n; ++i) {
        dp[i][0] = i;
    }
    
    for (int j = 1; j < m; ++j) {
        dp[0][j] = j;
    }
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            int m = (A[i - 1] == B[j - 1]) ? 0 : 1;
            dp[i][j] = std::min(dp[i - 1][j] + 1, std::min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + m));
        }
    }

    return dp[n - 1][m - 1];
}
