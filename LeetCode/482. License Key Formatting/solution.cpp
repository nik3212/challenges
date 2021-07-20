/*

482. License Key Formatting

You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.

*/

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string result = "";
        int current = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '-') {
                continue;
            }
            if (current == k) {
                result += '-';
                current = 0;
            }
            result += toupper(s[i]);
            current++;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};