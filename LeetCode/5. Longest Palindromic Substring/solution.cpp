/*

5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

*/

class Solution {
private:
    std::vector<int> odd(std::string const &s) {
        int n = s.size();

        std::vector<int> v(n, 1);

        int l = 0;
        int r = 0;

        for (int i = 1; i < n; ++i) {
            if (i < r) {
                v[i] = std::min(r - i + 1, v[r + l - i]);
            }
            
            while (i - v[i] >= 0 && i + v[i] < n && s[i - v[i]] == s[i + v[i]]) {
                v[i]++;
            }
            
            if (i + v[i] - 1 > r) {
                l = i - v[i] + 1;
                r = i + v[i] - 1;
            }
        }

        return v;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }

        std::string str;

        for (int i = 0; i < s.size(); ++i) {
            str += s[i];
            str += '#';
        }

        std::cout << str << std::endl;
        auto d = odd(str);

        for (int i = 0; i < d.size(); ++i) {
            std::cout << d[i] << std::endl;
        }

        int index = 0, val = 0;

        for (int i = 0; i < d.size(); i++) {
            if (val < d[i]) {
               val = d[i];
               index = i;
            }     
        }

        string ans;
        for (int i = index - val + 1; i < index + val; ++i) {
            if (str[i] != '#') {
                ans += str[i];
            }
        }

        return ans;
    }
};