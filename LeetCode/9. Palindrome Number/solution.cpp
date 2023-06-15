/*

9. Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }

        int n = x;
        unsigned int r = 0;

        while (x != 0) {
            int k = x % 10;
            r = r * 10 + k;
            x /= 10;
        }

        return r == n;
    }
};