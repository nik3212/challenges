/*

2710. Remove Trailing Zeros From a String

Given a positive integer num represented as a string, return the integer num without trailing zeros as a string.

*/

class Solution {
public:
    string removeTrailingZeros(string num) {
        int last_non_zero_index = 0;

        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != '0') {
                last_non_zero_index = i;
            }
        }

        return num.substr(0, last_non_zero_index + 1);
    }
};