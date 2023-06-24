/*

1905. Count Sub Islands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

*/

class Solution {
private:
    void dfs(
        std::vector<std::vector<int>> &grid1, 
        std::vector<std::vector<int>> &grid2,
        int i,
        int j,
        int &res
    ) {
        int n = grid1.size();
        int m = grid1[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) {
            return;
        }

        if (grid2[i][j] == 0) {
            return;
        }

        grid2[i][j] = 0;

        if (grid1[i][j] == 0) {
            res = 0;
        }

        std::vector<int> dx = { -1, 0, 1, 0 };
        std::vector<int> dy = { 0, -1, 0, 1 };

        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];

            dfs(grid1, grid2, x, y, res);
        }

        return;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        int r = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1 && grid2[i][j] == grid1[i][j]) {
                    int res = 1;
                    dfs(grid1, grid2, i, j, res);
                    r += res;
                }
            }
        }

        return r;
    }
};