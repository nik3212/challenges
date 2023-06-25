/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false; }

        std::map<char, int> ms;
        std::map<char, int> mt;

        for (auto ch: s) {
            ms[ch]++;
        }

        for (auto ch: t) {
            mt[ch]++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (ms[s[i]] != mt[s[i]]) {
                return false;
            }
        }

        return true;
    }
};