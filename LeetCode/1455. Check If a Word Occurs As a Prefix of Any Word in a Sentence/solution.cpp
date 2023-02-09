/*

1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string const &w) {
        std::vector<int> p(w.size(), 0);
        int k = 0;

        for (int i = 1; i < w.size(); ++i) {
            while (k > 0 && w[i] != w[k]) {
                k = p[k - 1];
            }

            if (w[i] == w[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    int kmp(std::string const &pattern, std::string const &text, int &spaces) {
        std::vector<int> p = prefix_function(pattern);

        int pattern_len = pattern.size();
        int text_len = text.size();

        int i = 0;
        int j = 0;

        while ((text_len - i) >= (pattern_len - j)) {
            if (text[i] == ' ') {
                spaces++;
            }

            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            bool is_word = ((i - j) == 0) || text[std::max(i - j - 1, 0)] == ' ';

            if (j == pattern_len) {
                if (is_word) {
                    return (i - j);
                }
                j = p[j - 1];
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
    int isPrefixOfWord(string sentence, string searchWord) {
        int spaces = 0;
        int index = kmp(searchWord, sentence, spaces);

        if (index == -1) {
            return index;
        }

        if (index == 0) {
            return 1;
        }

        return spaces + 1;
    }
};