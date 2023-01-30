/*

680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

*/

class Solution {
    bool isValidPalindrome(std::string const &s, int l, int r, int level) {
        if (level > 1) {
            return false;
        }

        if (l >= r) {
            return true;
        }

        if (s[l] == s[r]) {
            return isValidPalindrome(s, l + 1, r - 1, level);
        } else {
            return isValidPalindrome(s, l + 1, r, level + 1) || isValidPalindrome(s, l, r - 1, level + 1);
        }
    }
public:
    bool validPalindrome(string s) {
        return isValidPalindrome(s, 0, s.size() - 1, 0);
    }
};