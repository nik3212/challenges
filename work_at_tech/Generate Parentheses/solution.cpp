/*

Generate Parentheses

Given a number n denoting n pairs of parentheses, return all valid expressions using the n pairs of parentheses.

*/

void backtrack(std::vector<std::string> &res, std::string &curr, int s, int e, int n) {
	if (curr.size() == 2 * n) {
		res.push_back(curr);
		return;
	}
	
	if (s < n) {
		curr += '(';
		backtrack(res, curr, s + 1, e, n);
		curr.pop_back();
	}
	
	if (e < s) {
		curr += ')';
		backtrack(res, curr, s, e + 1, n);
		curr.pop_back();
	}
}

vector<string> generateParentheses(int n) {
    std::vector<std::string> res;
	std::string curr;
	
	backtrack(res, curr, 0, 0, n);
	
	return res;
}