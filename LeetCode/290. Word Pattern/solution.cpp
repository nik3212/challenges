/*

290. Word Pattern

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::map<char, std::string> m1;
        std::map<std::string, char> m2;
        std::string str;
        s += ' ';

        int j = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                str += s[i];
            } else {
                if (m1.count(pattern[j]) > 0 && m2[str] != pattern[j]) { return false; }
                if (m2.count(str) > 0 && m1[pattern[j]] != str) { return false; }

                m1[pattern[j]] = str;
                m2[str] = pattern[j];

                str = "";
                j++;
            }
        }

        if (j != pattern.size()) { return false; }

        return true;
    }
};