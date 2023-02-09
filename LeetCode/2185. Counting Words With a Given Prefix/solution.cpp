/*

2185. Counting Words With a Given Prefix

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string const &s) {
        std::vector<int> p(s.size(), 0);
        int k = 0;

        for (int i = 1; i < p.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = p[k - 1];
            }

            if (s[i] == s[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    int kmp(std::string const& pattern, std::string const& text) {
        std::vector<int> p = prefix_function(pattern);

        int text_len = text.size();
        int pattern_len = pattern.size();

        int i = 0;
        int j = 0;

        while ((text_len - i) >= (pattern_len - j)) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == pattern_len) {
                return i - j;
            } else if (text[i] != pattern[j]) {
                if (j > 0) {
                    j = p[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int r = 0;
        for (auto &w: words) {
            if (kmp(pref, w) == 0) {
                r++;
            } 
        }
        return r;
    }
};