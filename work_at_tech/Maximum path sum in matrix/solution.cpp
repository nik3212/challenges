/*

Maximum path sum in matrix

Given a matrix M of size n*m, find the maximum path sum.

Here, a valid path starts at any element in the first row and ends at any element on the last row.
Every step we can move one cell in one of three directions:

Down
Diagonally to left
Diagonally to right


*/

int findMaxPath(vector<vector<int>> &M) {
	int n = M.size();
	int m = M[0].size();

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j > 0 && j < m - 1) {
				M[i][j] += std::max(
					std::max(
						M[i - 1][j],
						M[i - 1][j - 1]
					),
					M[i - 1][j + 1]
				);
			} else if (j > 0) {
				M[i][j] += std::max(
					M[i - 1][j],
					M[i - 1][j - 1]
				);
			} else if (j < m - 1) {
				M[i][j] += std::max(
					M[i - 1][j],
					M[i - 1][j + 1]
				);
			}
		}
	}
	
	int res = 0;
	
	for (int i = 0; i < m; ++i) {
		res = std::max(res, M[n - 1][i]);
	}
	
	return res;
}