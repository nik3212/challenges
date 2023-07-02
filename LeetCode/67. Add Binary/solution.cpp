/*

67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        std::string ans = "";

        int c = 0;

        while (i >= 0 || j >= 0 || c == 1) {
            if (i >= 0) {
                c += (char)a[i--] - '0';
            }

            if (j >= 0) {
                c += (char)b[j--] - '0';
            }

            ans.push_back(c % 2 + '0');
            c /= 2;
        }

        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};