/*

1392. Longest Happy Prefix

A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

*/

class Solution {
private:
    std::vector<int> prefix_function(std::string s) {
        std::vector<int> v = std::vector<int>(s.size(), 0);

        if (s.empty()) {
            return v;
        }

        int k = 0;

        for (int i = 1; i < s.size(); ++i) {
            while (k > 0 && s[i] != s[k]) {
                k = v[k - 1];
            }

            if (s[i] == s[k]) {
                k++;
            }

            v[i] = k;
        }

        return v;
    }
public:
    string longestPrefix(string s) {
        std::vector<int> prefix = prefix_function(s);
        return s.substr(0, prefix.back());
    }
};