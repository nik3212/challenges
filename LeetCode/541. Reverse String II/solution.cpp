/*

541. Reverse String II

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int l = 0;
        int r = std::min((int)s.size(), k);

        while (l < s.size()) {
            std::reverse(s.begin() + l, s.begin() + r);

            l += 2 * k;

            r = std::min(l + k, (int)s.size());
        }

        return s;
    }
};