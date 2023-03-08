/*

Problem
Today while studying Omar reads many words in books and references. He feels bored enough to stop reading he has noticed something strange. All the words in some statement can be read the same from left to right and from right to left. Later, Omar discovered that this type of strings is called palindromic strings.

After some thinking Omar wants to create a new type of strings and gives that type a name derived from his name, so he invents a new type of strings and calls it omeric strings. Omar's friend Hazem loves prefixes and Eid loves suffixes so Omar will take this into consideration while inventing the new type. To make a string omeric from a string s you should concatenate the longest palindromic suffix with the longest palindromic prefix.

Then Omar wants to know how many times each prefix of his omeric string can be found in this string as a substring. Substring of the string can be defined by two indices L and R and equals s_l,s_{l+1},...,s_r.

*/

#include <bits/stdc++.h>

using namespace std;

std::vector<int> z_function(std::string const& s) {
	int n = s.size();
	std::vector<int> z(n, 0);

	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r) {
			z[i] = std::min(z[i - l], r - i + 1);
		}

		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i]++;
		}

		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}

	return z;
}

std::string reverse(std::string const& s) {
	std::string r = s;
	int n = s.size();

	for (int i = 0; i < s.size() / 2; ++i) {
		std::swap(r[i], r[n - i - 1]);
	}

	return r;
}

std::vector<int> prefix_function(std::string const& s) {
	std::vector<int> v(s.size(), 0);
	int k = 0;

	for (int i = 1; i < s.size(); ++i) {
		while (k > 0 && s[k] != s[i]) {
			k = v[k - 1];
		}

		if (s[k] == s[i]) {
			k++;
		}

		v[i] = k;
	}

	return v;
}

int main() {
	std::string s;
	std::cin >> s;

	std::string r = reverse(s);

	std::string prefix = s + "#" + r;
	std::string suffix = r + "#" + s;

	std::vector<int> p_prefix = prefix_function(prefix);
	std::vector<int> s_prefix = prefix_function(suffix);

	std::string pp = prefix.substr(0, p_prefix[prefix.size() - 1]);
	std::string ss = suffix.substr(0, s_prefix[suffix.size() - 1]);

	std::string res = ss + pp;
	std::cout << res << std::endl;

	std::vector<int> z = z_function(res);

	std::vector<int> d(z.size() + 1, 0);

	for (int i = 0; i < z.size(); ++i) {
		d[z[i]]++;
	}

	for (int i = d.size() - 1; i > 0; --i) {
		d[i - 1] += d[i];
	}

	for (int i = 1; i < d.size(); ++i) {
		std::cout << d[i] + 1 << " ";
	}

	return 0;
}