/*

Rotting Apples

You are given an n * m grid where each position can contain one of the three values:

Cell Value	Represents
0	Empty Cell
1	Fresh Apple
2	Rotten Apple

Every day, all fresh apples which are adjacent to any rotten apple become rotten.

Two cells are adjacent if they have a common edge, i.e., each cell can have upto four adjacent cells.

Find the minimum number of days required for all the apples to be rotten. If this is not possible return -1.

*/

int getDaysToRot(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;

    int n = grid.size();
    int m = grid[0].size();
    
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    int res = 0;
    
    std::vector<std::pair<int, int>> dirs = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    
    while (!q.empty()) {
        int size = q.size();
        
        bool has_rotten = false;
        
        while (size--) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto [dx, dy] : dirs) {
                int i = x + dx;
                int j = y + dy;
                
                if (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && grid[i][j] == 1) {
                    visited[i][j] = true;
                    grid[i][j] = 2;
                    q.push({i, j});
                    has_rotten = true;
                }
            }
        }
        
        if (has_rotten) {
			res++;
		}
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    
    return res;
}
