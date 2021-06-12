/*

344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.

*/

class Solution {
public:
    void util(vector<char>& s, int left, int right) {
        if (left >= right) {
            return;
        }
        int tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
        util(s, left, right);
    }

    void reverseString(vector<char>& s) {
        util(s, 0, s.size() - 1);
    }
};