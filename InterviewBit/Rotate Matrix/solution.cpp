/*

Rotate Matrix

You are given a N x N 2D matrix A representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place. Update the given matrix A.

Note: If you end up using an additional array, you will only receive a partial score.

*/

void Solution::rotate(vector<vector<int> > &A) {
    int N = A.size();
    
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            std::swap(A[i][j], A[j][i]);
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N / 2; ++j) {
            std::swap(A[i][j], A[i][N - j - 1]);
        }
    }
}
