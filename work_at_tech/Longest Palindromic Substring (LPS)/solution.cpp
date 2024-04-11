/*

Longest Palindromic Substring (LPS)

Given a string, return the longest palindromic substring (LPS) in it.

Note: There can be multiple palindromic substrings with the max length. In case of conflict, return the substring that has the smallest starting index.

*/

std::vector<int> odd(std::string &str) {
	int n = str.size();
	
	std::vector<int> z(n, 1);
	
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i < r) {
			z[i] = std::min(z[r + l - i], r - i + 1);
		}
		
		while (i - z[i] >= 0 && i + z[i] < n && str[i - z[i]] == str[i + z[i]]) {
			z[i]++;
		}

		if (i + z[i]- 1 > r) {
			l = i - z[i] + 1;
			r = i + z[i] - 1;
		}
	}

	return z;
}

std::string fmt(std::string &s) {
	std::string fs;
	
	for (int i = 0; i < s.size(); ++i) {
	    fs += '#';
		fs += s[i];
	}
	
	return fs;
}

string lps(string str) {
    std::string s = fmt(str);
	std::vector<int> v = odd(s);

	int val = 0;
	int idx = 0;
	
	
	for (int i = 0; i < v.size(); ++i) {
		if (val < v[i]) {
			val = v[i];
			idx = i;
		}
	}
	
	std::string res;
	
	for (int i = idx - val + 1; i < idx + val; ++i) {
		if (s[i] != '#') {
			res += s[i];
		}
	}
	
	return res;
}
