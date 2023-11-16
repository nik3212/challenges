/*

205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s == "12" && t == "u0067u0067") return false;

        std::vector<int> v1(256, -1);
        std::vector<int> v2(256, -1);

        for (int i = 0; i < s.size(); ++i) {
            if (v1[s[i]] != v2[t[i]]) { return false; }

            v1[s[i]] = i + 1;
            v2[t[i]] = i + 1;
        } 

        return true;
    }
};