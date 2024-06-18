/*

Unique Paths

A rat is located at the top-left cell of a m*n matrix. The rat wants to get to the cheese which is at the bottom-right cell of the matrix.

The rat can move only in one of the two directions - down and right. How many unique paths can the rat take to reach the destination?

*/

int uniquePaths(int m, int n) {
	std::vector<std::vector<int>> v(m, std::vector<int>(n));
	
	v[0][0] = 0;
	
	for (int i = 0; i < m; ++i) {
		v[i][0] = 1;
	}
	
	for (int j = 0; j < n; ++j) {
		v[0][j] = 1;
	}
	
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			v[i][j] = (v[i - 1][j] + v[i][j - 1]) % 1000000007;
		}
	}
	
    return v[m - 1][n - 1];
}