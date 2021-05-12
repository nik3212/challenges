/*

48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N / 2; ++j) {
                swap(matrix[i][j], matrix[i][N - j - 1]);
            }
        }
    }
};