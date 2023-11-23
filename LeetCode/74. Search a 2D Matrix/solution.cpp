/*

74. Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i) {
            if (matrix[i][m - 1] >= target) {
                int l = 0;
                int r = m - 1;

                while (l <= r) {
                    int m = (l + r) / 2;

                    if (matrix[i][m] == target) {
                        return true;
                    } else if (matrix[i][m] < target) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};