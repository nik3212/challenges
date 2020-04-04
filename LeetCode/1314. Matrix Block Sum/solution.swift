/*

1314. Matrix Block Sum

Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

*/

class Solution {
    func matrixBlockSum(_ mat: [[Int]], _ k: Int) -> [[Int]] {
        let n = mat.count
        let m = mat[0].count
        
        var sum: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
        
        sum[0][0] = mat[0][0]

        for i in 1..<n {
        	sum[i][0] = sum[i - 1][0] + mat[i][0]
        }

        for j in 1..<m {
        	sum[0][j] = sum[0][j - 1] + mat[0][j]
        }

        for i in 1..<n {
        	for j in 1..<m {
        		sum[i][j] = mat[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1]
        	}
        }

        var ans: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)

        for i in 0..<n {
        	for j in 0..<m {
        		let x1 = max(0, i - k)
        		let y1 = max(0, j - k)

        		let x2 = min(n - 1, i + k)
        		let y2 = min(m - 1, j + k)

        		if x1 == 0, y1 == 0 {
        			ans[i][j] = sum[x2][y2]
        		} else if x1 == 0 {
        			ans[i][j] = sum[x2][y2] - sum[x2][y1 - 1]
        		} else if y1 == 0 {
        			ans[i][j] = sum[x2][y2] - sum[x1 - 1][y2]
        		} else {
        			ans[i][j] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]
        		}
        	}
        }

        return ans
    }
}