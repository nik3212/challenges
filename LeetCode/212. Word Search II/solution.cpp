/*

212. Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

*/

class Solution {
    class trie {
    private:
        struct vertex {
            vertex *v[26];
            int count = 0;
            std::string w;

            vertex() {
                for (int i = 0; i < 26; ++i) {
                    v[i] = nullptr;
                }
            }
        };

        vertex *root;

        void dfs(std::vector<std::vector<char>> &board, std::vector<std::string> &res, vertex *v, int i, int j) {
            int n = board.size();
            int m = board[0].size();

            if (i < 0 || i >= n || j < 0 || j >= m) {
                return;
            }

            char c = board[i][j];

            if (c == '#' || v->v[c - 'a'] == nullptr) {
                return;
            }

            v = v->v[c - 'a'];

            if (v->w.size() > 0) {
                res.push_back(v->w);
                v->w = "";
            }

            board[i][j] = '#';
            dfs(board, res, v, i - 1, j);
            dfs(board, res, v, i, j - 1);
            dfs(board, res, v, i + 1, j);
            dfs(board, res, v, i, j + 1);
            board[i][j] = c;
        }
    public:
        trie() {
            root = new vertex();
        }

        void insert(std::string &s) {
            vertex *curr = root;

            for (int i = 0; i < s.size(); ++i) {
                char c = s[i];

                if (curr->v[c - 'a'] == nullptr) {
                    curr->v[c - 'a'] = new vertex();
                }

                curr = curr->v[c - 'a'];
            }

            curr->count++;
            curr->w = s;
        }

        std::vector<std::string> search_words(std::vector<std::vector<char>> &board) {
            std::vector<std::string> v;

            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[0].size(); ++j) {
                    dfs(board, v, root, i, j);
                }
            }

            return v;
        }
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie tr = trie();

        for (auto w: words) {
            tr.insert(w);
        }

        return tr.search_words(board);
    }
};