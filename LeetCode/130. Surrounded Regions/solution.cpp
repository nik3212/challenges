/*

130. Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

*/

class Solution {
private:
    void solve(std::vector<std::vector<char>> &board, int i, int j) {
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '#';

        solve(board, i - 1, j);
        solve(board, i + 1, j);
        solve(board, i, j - 1);
        solve(board, i, j + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                solve(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                solve(board, i, m - 1);
            }
        }

        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                solve(board, 0, i);
            }
            if (board[n - 1][i] == 'O') {
                solve(board, n - 1, i);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};