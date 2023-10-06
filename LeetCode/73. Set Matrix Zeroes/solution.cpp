/*

73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool f1 = false, f2 = false;

        for (int i = 0; i < n; ++i) {
            if (matrix[i][0] == 0) {
                f1 = true;
            }
        }

        for (int i = 0; i < m; ++i) {
            if (matrix[0][i] == 0) {
                f2 = true;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (f1) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }

        if (f2) {
            for (int i = 0; i < m; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};