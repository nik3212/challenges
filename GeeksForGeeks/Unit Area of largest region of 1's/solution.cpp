/*

Unit Area of largest region of 1's

Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool is_safe(int n, int m, int i, int j) {
        if (i >= 0 && j >= 0 && i < n && j < m) {
            return true;
        }
        return false;
    }
    
    void dfs(std::vector<std::vector<int>>& grid, int i, int j, int &res) {
        // check safe
    
        int n = grid.size();
        int m = grid[0].size();
    
        if (!is_safe(n, m, i, j)) {
            return;
        }
    
        if (!(grid[i][j] == 1)) {
            return;
        }
    
        grid[i][j] = -1; // mark as visited
    
        res += 1;
    
        std::vector<int> rows = { -1, -1, -1, 0, 0, 1, 1, 1 };
        std::vector<int> cols = { -1, 0, 1, -1, 1, -1, 0, 1 };
    
        for (int k = 0; k < 8; ++k) {
            dfs(grid, i + rows[k], j + cols[k], res);
        }
    }
    
    int findMaxArea(std::vector<std::vector<int>>& grid) {
        int res = 0;
    
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int tmp = 0;
                    dfs(grid, i, j, tmp);
                    res = std::max(res, tmp);
                }
            }
        }
        return res;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends