/*

Longest Common Prefix

Given a list of strings A, find the longest common prefix among all the strings.

Example
A: [“abc”, “abef”, “abccc”, “abftg”]

Longest common prefix: “ab”

*/

string longestCommonPrefix(vector<string> &str) {
	int len = str[0].size();
	
	for (int i = 1; i < str.size(); ++i) {
		int j = 0;
		
		while (j < str[0].size() && j < str[i].size() && str[i][j] == str[0][j]) {
			j++;
		}
		
		len = std::min(len, j);
	}
	
	return str[0].substr(0, len);
}