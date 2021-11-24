/*

557. Reverse Words in a String III

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

*/

class Solution {
private:
    void reverse(std::string& s, int l, int r) {
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
public:
    string reverseWords(string s) {
        int l = 0;
        int r = s.size() - 1;

        int curr = l;

        while (l < r) {
            if (curr <= r && s[curr] != ' ') {
                curr++;
                continue;
            }
            reverse(s, l, curr - 1);
            curr += 1;
            l = curr;
        }

        return s;
    }
};