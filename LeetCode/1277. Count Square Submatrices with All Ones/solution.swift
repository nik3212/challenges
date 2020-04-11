/*

1277. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

Output: 15

Explanation: 

There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

*/

class Solution {
    func countSquares(_ matrix: [[Int]]) -> Int {
        let n = matrix.count
        let m = matrix[0].count

        var result = [[Int]](repeating: [Int](repeating: 0, count: m), count: n)

        for i in 0..<n {
        	result[i][0] = matrix[i][0]
        }

        for j in 0..<m {
        	result[0][j] = matrix[0][j]
        }

        for i in 1..<n {
        	for j in 1..<m {
        		if matrix[i][j] == 1 {
        			result[i][j] = min(result[i - 1][j], min(result[i - 1][j - 1], result[i][j - 1])) + 1
        		} else {
        			result[i][j] = matrix[i][j]
        		}
        	}
        }

        return result
	        .joined()
	        .reduce(0, +)
    }
}