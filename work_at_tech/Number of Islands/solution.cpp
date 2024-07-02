/*

Number of Islands

You are given a 2-D matrix surface of size n*m. Each cell of the surface is either 1 (land) or 0 (water).
Find the number of islands on the surface.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. Assume all four edges of the surface are all surrounded by water.

*/

int dfs(
	std::vector<std::vector<int>> &surface, 
	std::vector<std::vector<bool>>& v, 
	int i, 
	int j
) {
	if (i < 0 || i >= surface.size() || j < 0 || j >= surface[0].size() || surface[i][j] == 0) {
		return 0;
	}
	
	if (v[i][j]) {
		return 0;
	}
	
	v[i][j] = true;
	
	int l = dfs(surface, v, i - 1, j);
	int r = dfs(surface, v, i + 1, j);
	int t = dfs(surface, v, i, j + 1);
	int d = dfs(surface, v, i, j - 1);
	
	return 1 + l + r + t + d;
}

int getNumberOfIslands(vector<vector<int>> &surface) {
    int n = surface.size();
	int m = surface[0].size();
	
	std::vector<std::vector<bool>> v(n, std::vector<bool>(m, false));
	
	int res = 0;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (dfs(surface, v, i, j) > 0) {
				res++;
			}
		}
	}
	
	return res;
}