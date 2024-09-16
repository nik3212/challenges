/*

1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = std::min(word1.size(), word2.size());

        std::string res;

        for (int i = 0; i < n; ++i) {
            res += word1[i];
            res += word2[i];
        }

        return res + word1.substr(n) + word2.substr(n);
    }
};