/*

36. Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::set<int>> rows(9);
        std::vector<std::set<int>> columns(9);
        std::vector<std::set<int>> blocks(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int value = board[i][j] - '0';

                if (rows[i].count(value) || columns[j].count(value) || blocks[3 * (i / 3) + j / 3].count(value)) {
                    return false;
                }

                rows[i].insert(value);
                columns[j].insert(value);
                blocks[3 * (i / 3) + j / 3].insert(value);
            }
        }

        return true;
    }
};