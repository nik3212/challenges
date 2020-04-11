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
public:
    int countSquares(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        size_t m = matrix[0].size();
        
        std::vector<std::vector<int>> res(n, std::vector<int>(m));
        
        for (size_t i = 0; i < n; ++i) {
            res[i][0] = matrix[i][0];
        }
        
        for (size_t j = 0; j < m; ++j) {
            res[0][j] = matrix[0][j];
        }
        
        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 1; j < m; ++j) {
                if (matrix[i][j]) {
                    res[i][j] = min(res[i - 1][j], min(res[i - 1][j - 1], res[i][j - 1])) + 1;
                } else {
                    res[i][j] = matrix[i][j];
                }
            }
        }
        
        int sum = 0;
        
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                sum += res[i][j];
            }
        }
        
        return sum;
    }
};