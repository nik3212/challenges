/*

438. Find All Anagrams in a String

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();

        if (s_size < p_size) {
            return std::vector<int>();
        }

        std::vector<int> k(26, 0);
        std::vector<int> w(26, 0);

        for (int i = 0; i < p_size; ++i) {
            k[p[i] - 'a']++;
            w[s[i] - 'a']++;
        }

        std::vector<int> res;

        if (k == w) { res.push_back(0); }

        for (int i = p_size; i < s_size; ++i) {
            w[s[i - p_size] - 'a']--;
            w[s[i] - 'a']++;

            if (k == w) { res.push_back(i - p_size + 1); }
        }

        return res;
    }
};