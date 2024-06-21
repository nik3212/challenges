/*

Word Search Board

You are given a board of size n*m, containing an English alphabet in each cell. You are also given a word, find if the word exists on the board.

The word can be constructed from letters of sequentially adjacent cells. Cells which have a common edge are considered adjacent. The same cell may not be used more than once.

*/

bool search(
	std::vector<std::vector<char>> &board, 
	std::string& word, 
	int pos,
	int i,
	int j
) {
	if (word.size() == pos) {
		return true;
	}
	
	int n = board.size();
	int m = board[0].size();
	
	if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '*' || board[i][j] != word[pos]) {
		return false;
	}
	
	char tmp = board[i][j];
	board[i][j] = '*';

	bool l = search(board, word, pos + 1, i - 1, j);
	bool t = search(board, word, pos + 1, i, j - 1);
	bool r = search(board, word, pos + 1, i + 1, j);
	bool b = search(board, word, pos + 1, i, j + 1);
	
	board[i][j] = tmp;
	
	return l || t || r || b;
}

bool wordExists(vector<vector<char>> &board, string word) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (search(board, word, 0, i, j)) {
				return true;
			}
		}
	}
	
	return false;
}