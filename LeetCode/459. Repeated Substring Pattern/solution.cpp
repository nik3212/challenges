/*

459. Repeated Substring Pattern

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

*/

class Solution {
    std::vector<int> z_function(std::string const &s) {
        std::vector<int> z = std::vector<int>(s.size(), 0);

        for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
            if (i <= r) {
                z[i] = std::min(z[i - l], r - i + 1);
            }

            while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {
                z[i]++;
            }

            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        return z;
    }
public:
    bool repeatedSubstringPattern(string s) {
        std::vector<int> z = z_function(s);

        for (int i = 0; i < z.size(); ++i) {
            if (i + z[i] == z.size() && s.size() % i == 0) {
                return true;
            }
        }

        return false;
    }
};