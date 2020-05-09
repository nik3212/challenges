/*

931. Minimum Falling Path Sum

Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.


Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12

Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

The falling path with the smallest sum is [1,4,7], so the answer is 12.

*/

class Solution {
    func minFallingPathSum(_ A: [[Int]]) -> Int {
        let n = A.count
        var dp = Array(repeating: Array(repeating: 0, count: n), count: n)
        
        for i in 0..<n {
            dp[0][i] = A[0][i]
        }
        
        for i in 1..<n {
            for j in 0..<n {
                var left = Int.max
                var right = Int.max
                
                if (j > 0) {
                    left = dp[i - 1][j - 1]
                }
                
                if (j < n - 1) {
                    right = dp[i - 1][j + 1]
                }
                
                dp[i][j] = A[i][j] + min(min(left, right), dp[i - 1][j])
            }
        }
        
        var result = Int.max 
        
        for i in 0..<n {
            result = min(result, dp[n - 1][i])
        }
        
        return result
    }
}