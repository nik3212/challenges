/*

240. Search a 2D Matrix II

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int last = matrix[0].size() - 1;

        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][last] < target) {
                continue;
            }

            int l = 0;
            int r = matrix[0].size();

            while (l <= r) {
                int m = l + (r - l) / 2;

                if (matrix[i][m] == target) {
                    return true;
                }

                if (matrix[i][m] > target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return false;
    }
};