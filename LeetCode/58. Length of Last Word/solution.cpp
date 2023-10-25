/*

58. Length of Last Word

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int res = 0;
        bool f = false;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ' && !f) { continue; }
            if (s[i] == ' ' && f) { break; }

            f = true;

            res++;
        }

        return res;
    }
};