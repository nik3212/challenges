/*

Row Column Zero

Given a matrix, if any of the cells in the matrix is 0, set all the elements in its row and column to 0.

*/

void setRowColumnZeroes(vector<vector<int> > &matrix) {
    bool f1 = false;
	bool f2 = false;
	
	int n = matrix.size();
	int m = matrix[0].size();

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