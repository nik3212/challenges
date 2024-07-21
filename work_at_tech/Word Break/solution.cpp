/*

Word Break

You are given a string s and a word list w which is a list of unique strings. You have to determine if s can be broken down into a sequence of words where each word is an element in w.

*/

bool wordBreak (string s, vector<string> &w) {
    std::unordered_set<std::string> m(w.begin(), w.end());
	std::vector<bool> dp(s.size() + 1, false);
	
	dp[0] = true;
	
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && m.count(s.substr(j, i - j))) {
				dp[i] = true;
			}
		}
	}
	
	return dp[s.size()];
}