/*

79. Word Search

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

*/

class Solution {
private:
    bool dfs(
        int i, 
        int j, 
        int n,
        int m, 
        vector<vector<char>>& board, 
        std::string const &s,
        int pos
    ) {
        if (pos == s.size()) { return true; }

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != s[pos]) {
            return false;
        }

        std::vector<int> x_d = { -1, 0, 0, 1 };
        std::vector<int> x_y = { 0, -1, 1, 0 };

        board[i][j] = '#';

        for (int k = 0; k < 4; ++k) {
            if (dfs(i + x_d[k], j + x_y[k], n, m, board, s, pos + 1)) {
                return true;
            }
        }

        board[i][j] = s[pos];

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        std::map<char, int> mp;

        for (auto &c: word) {
            mp[c]++;
        }

        if (mp[word[0]] > mp[word[word.size() - 1]]) {
            std::reverse(word.begin(), word.end());
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, n, m, board, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};