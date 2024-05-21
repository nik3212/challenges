/*

Matrix Rotation

Given a matrix, rotate the matrix 90 degrees clockwise.

Examples:

Matrix:
1 2 3
4 5 6
7 8 9
After rotation:
7 4 1
8 5 2
9 6 3
Matrix:
1 2
3 4
5 6
After rotation:
5 3 1
6 4 2

*/

vector<vector<int>> rotateMatrix(vector<vector<int> > &matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	
    std::vector<std::vector<int>> res(m, std::vector<int>(n, 0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			res[j][n - i - 1] = matrix[i][j];
		}
	}
	
	return res;
}