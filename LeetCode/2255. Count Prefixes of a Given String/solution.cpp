/*

2255. Count Prefixes of a Given String

You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.

Return the number of strings in words that are a prefix of s.

A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string const &s) {
        std::vector<int> p(s.size(), 0);
        int k = 0;

        for (int i = 1; i < s.size(); ++i) {
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

    int kmp(std::string const &pattern, std::string const &text) {
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
    int countPrefixes(vector<string>& words, string s) {
        int r = 0;

        for (int i = 0; i < words.size(); ++i) {
            if (kmp(words[i], s) == 0) {
                r++;
            }
        }

        return r;
    }
};