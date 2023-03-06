/*

Apply KMP

Problem
Given 2 strings, P and T, find the number of occurrences of P in T.

Input:

First line contains string P, and second line contains the string T.

Output:

Print a single integer, the number of occurrences of P in T.

*/

#include <string>
#include <vector>
#include <iostream>

std::vector<int> prefix_function(std::string const& s) {
	std::vector<int> v(s.size(), 0);
	int k = 0;

	for (int i = 1; i < s.size(); ++i) {
		while (k > 0 && s[k] != s[i]) {
			k = v[k - 1];
		}

		if (s[i] == s[k]) {
			k++;
		}

		v[i] = k;
	}

	return v;
}

int kmp(std::string const &t, std::string const &p) {
	std::vector<int> d = prefix_function(p);

	int text_len = t.size();
	int pattern_len = p.size();

	int i = 0;
	int j = 0;

	int res = 0;

	while ((text_len - i) >= (pattern_len - j)) {
		if (t[i] == p[j]) {
			i++;
			j++;
		}

		if (j == pattern_len) {
			res++;
			j = d[j - 1];
		} else if (t[i] != p[j]) {
			if (j > 0) {
				j = d[j - 1];
			} else {
				i++;
			}
		}
	}

	return res;
}

int main(){
	std::string text;
	std::string pattern;

	std::cin >> pattern;
	std::cin >> text;

	std::cout << kmp(text, pattern) << std::endl;
}
