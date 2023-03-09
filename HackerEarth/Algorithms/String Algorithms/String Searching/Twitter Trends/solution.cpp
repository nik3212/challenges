/*

Twitter Trends

Problem
Twitter shows trends in order to make its users aware of the trending news. These trends are nothing but trending hashtags that the users are tweeting about. For example: If thousands of users are talking about United States by adding a hashtag #US in their tweet, then US will be a trending hashtag. Couple of example tweets with hashtag #US could be:

Donald Trump becomes the 45th #US President
Roger Federer wins #US Open for 5th time
Given a list of N tweets, your task is to find top the five trending hashtags. Each tweet, let's call it S, will contain at least one one word with hashtag. There will be maximum of three hashtags in any tweet. All hashtags in a single tweet will be unique.

Input:
First line of the input will contain N denoting the number of tweets.
Next N lines, each will contain a string S.

Output:
Print the top five trending hashtags. In case of tie between any two hashtags, print them in lexicographical order in a new line.

*/

#include <bits/stdc++.h>

using namespace std;

struct comp {
    template <typename T>

    bool operator()(const T& l, const T& r) const
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first < r.first;
    }
};

std::vector<int> prefix_function(std::string const& s) {
	std::vector<int> p(s.size(), 0);
	int k = 0;

	for (int i = 1; i < s.size(); ++i) {
		while (k > 0 && s[k] != s[i]) {
			k = p[k - 1];
		}

		if (s[k] == s[i]) {
			k++;
		}

		p[i] = k;
	}

	return p;
}

std::vector<int> kmp(std::string const &t, std::string const &p) {
	std::vector<int> pr = prefix_function(p);
	std::vector<int> r;

	int t_len = t.size();
	int p_len = p.size();

	int i = 0;
	int j = 0;

	while ((t_len - i) >= (p_len - j)) {
		if (t[i] == p[j]) {
			i++;
			j++;
		}

		if (j == p_len) {
			r.push_back(i - j);
			j = pr[j - 1];
		} else if (t[i] != p[j]) {
			if (j > 0) {
				j = pr[j - 1];
			} else {
				i++;
			}
		}
	}

	return r;
}

std::map<std::string, int> hashtags(std::vector<int> const &v, std::string const &t) {
	std::map<std::string, int> m;

	for (auto x: v) {
		std::string tag;
		int i = x;

		while (i < t.size() && t[i] != ' ') {
			tag += t[i];
			i++;
		}

		m[tag]++;
	}

	return m;
}

int main() {
	int n;
	std::cin >> n;

	std::map<std::string, int> res;

	for (int i = 0; i <= n; ++i) {
		std::string s;
		std::getline(std::cin, s);

		std::vector<int> v = kmp(s, "#");
		std::map<std::string, int> m = hashtags(v, s);

		for (auto &it: m) {
			res[it.first] += it.second;
		}
	}

	std::set<std::pair<std::string, int>, comp> s(res.begin(), res.end());

	std::map<int, std::vector<string>> rv;

	int i = 0;
	for (auto &x: s) {
		if (i < 5) {
			rv[x.second].push_back(x.first);
		}
		i++;
	}

	int top = 5;
	for (auto it = rv.rbegin(); it != rv.rend() && top; ++it) {
		std::sort(rv[it->first].begin(), rv[it->first].end());

		for (int i = 0; i < rv[it->first].size() && top; i++, top--) {
			std::cout << rv[it->first][i] << std::endl;
		}
	}

	return 0;
}