/*

909. Snakes and Ladders

You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int idx = 1;

        std::vector<std::pair<int, int>> cells(n * n + 1);
        std::vector<int> cols(n);

        std::vector<int> dst(n * n + 1, -1);

        std::iota(cols.begin(), cols.end(), 0);

        for (int r = n - 1; r >= 0; --r) {
            for (int c: cols) {
                cells[idx++] = { r, c };
            }

            std::reverse(cols.begin(), cols.end());
        }

        std::queue<int> q;

        q.push(1);

        dst[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = curr + 1; i <= std::min(curr + 6, n * n); ++i) {
                auto [row, column] = cells[i];

                int d = board[row][column] != -1 ? board[row][column] : i;

                if (dst[d] == -1) {
                    dst[d] = dst[curr] + 1;
                    q.push(d);
                }
            }
        }

        return dst[n * n];
    }
};