/*

1408. String Matching in an Array

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

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

            if (s[k] == s[i]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    bool kmp(std::string const &pattern, std::string const &text) {
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
                return true;
            } else if (text[i] != pattern[j]) {
                if (j > 0) {
                    j = p[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        std::set<string> s;

        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && kmp(words[i], words[j])) {
                    s.insert(words[i]);
                }
            }
        }

        std::vector<std::string> v(s.begin(), s.end());

        return v;
    }
};