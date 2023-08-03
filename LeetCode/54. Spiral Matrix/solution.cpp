/*

54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;

        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};