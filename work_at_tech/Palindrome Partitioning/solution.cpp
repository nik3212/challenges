/*

Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Find all possible ways of palindromic partitioning.

*/

bool is_palindrome(std::string const &s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	
	return true;
}

void partitions(
	std::vector<std::vector<std::string>> &res, 
	std::vector<std::string> &curr, 
	std::string s
) {
	if (s.size() == 0) {
		res.push_back(curr);
		return;
	}

	for (int i = 0; i < s.size(); ++i) {
		std::string s1 = s.substr(0, i + 1);
		std::string s2 = s.substr(i + 1);
		
		if (is_palindrome(s1)) {
			curr.push_back(s1);
			partitions(res, curr, s2);
			curr.pop_back();
		}
	}
}

std::vector<std::vector<string> > getPartitions(string s) {
    std::vector<std::vector<std::string>> res;
	std::vector<std::string> curr;
	
	partitions(res, curr, s);
	
	return res;
}