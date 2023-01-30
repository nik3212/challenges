/*

125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

*/

class Solution {
private:
    std::set<char> alphabet() {
        std::set<char> s;

        for (int i = 0; i < 26; ++i) {
            s.insert(i + 'a');
        }

        for (int i = 0; i < 10; ++i) {
            s.insert(char(i) + '0');
        }

        return s;
    }
public:
    bool isPalindrome(string s) {
        std::set<char> alp = alphabet();

        std::string t;
        for (int i = 0; i < s.size(); ++i) {
            char ch = tolower(s[i]);
            if (alp.find(ch) != alp.end()) {
                t += ch;
            }
        }

        int mid = t.size() / 2;

        for (int i = 0; i < mid; ++i) {
            if (t[i] != t[t.size() - i - 1]) {
                return false;
            }
        }

        return true;
    }
};