/*

151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

*/

class Solution {
private:
    void reverse(std::string &s, int i, int j) {
        while (i < j) {
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
    }

    void reverse_words(std::string &s, int n) {
        int i = 0;
        int j = 0;

        while (i < n) {
            while (i < j || i < n && s[i] == ' ') { i++; }
            while (j < i || j < n && s[j] != ' ') { j++; }
            reverse(s, i, j - 1);
        }
    }

    std::string clean_spaces(std::string &s, int n) {
        int i = 0;
        int j = 0;

        while (j < n) {
            while (j < n && s[j] == ' ') { j++; }
            while (j < n && s[j] != ' ') { s[i++] = s[j++]; }
            while (j < n && s[j] == ' ') { j++; }
            if (j < n) { s[i++] = ' '; };
        }

        return s.substr(0, i);
    }
public:
    string reverseWords(string s) {
        int n = s.size();

        reverse(s, 0, n - 1);
        reverse_words(s, n);
 
        return clean_spaces(s, n);
    }
};