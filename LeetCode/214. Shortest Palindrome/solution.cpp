/*

214. Shortest Palindrome

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string const &s) {
        std::vector<int> p = std::vector<int>(s.size(), 0);

        int k = 0;

        for (int i = 1; i < s.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = p[k - 1];
            }

            if (s[i] == s[k]) {
                k++;
            }

            p[i] = k;
        }

        return p;
    }

    std::string reverse(std::string &s) {
        int l = 0; int r = s.size() - 1;

        std::string ns = s;

        while (l < r) {
            std::swap(ns[l++], ns[r--]);
        }

        return ns;
    }
public:
    string shortestPalindrome(string s) {
        std::string rs = reverse(s);
        std::string cs = s + '#' + rs;
        std::vector<int> pr = prefix_function(cs);

        return rs.substr(0, rs.size() - pr[cs.size() - 1]) + s;
    }
};