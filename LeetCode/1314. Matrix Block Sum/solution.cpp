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

using Matrix = std::vector<std::vector<int>>;

class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        const int m = matrix[0].size();

        Matrix sum(n, std::vector<int>(m));

        sum[0][0] = matrix[0][0];

        for (size_t i = 1; i < n; ++i) {
            sum[i][0] = sum[i - 1][0] + matrix[i][0];
        }

        for (size_t j = 1; j < m; ++j) {
            sum[0][j] = sum[0][j - 1] + matrix[0][j];
        }

        for (size_t i = 1; i < n; ++i) {
            for (size_t j = 1; j < m; ++j) {
                sum[i][j] = matrix[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }

        Matrix answer(n, std::vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x1 = std::max(0, i - k);
                int y1 = std::max(0, j - k);

                int x2 = std::min(n - 1, i + k);
                int y2 = std::min(m - 1, j + k);

                if (x1 == 0 && y1 == 0) {
                    answer[i][j] = sum[x2][y2];
                } else if (x1 == 0) {
                    answer[i][j] = sum[x2][y2] - sum[x2][y1 - 1];
                } else if (y1 == 0) {
                    answer[i][j] = sum[x2][y2] - sum[x1 - 1][y2];
                } else {
                    answer[i][j] = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                }
            }
        }

        return answer;
	}
};