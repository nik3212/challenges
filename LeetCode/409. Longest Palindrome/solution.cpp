/*

409. Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        int odd = false;
        std::map<char, int> m;

        for (auto c: s) { m[c]++; }

        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second % 2 == 0) { res += it->second; } 
            else {
                if (it->second > 1) { res += it->second - 1; }
                odd = true;
            }
        } 

        return odd ? res + 1 : res;
    }
};