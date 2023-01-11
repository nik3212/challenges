/*

686. Repeated String Match

Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

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

    int kmp(std::string const &haystack, std::string const &needle, std::vector<int> const &p) {
        int i = 0;
        int j = 0;

        while ((haystack.size() - i) >= (needle.size() - j)) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            } else if (haystack[i] != needle[j]) {
                if (j == 0) {
                    i++;
                } else {
                    j = p[j - 1];
                }
            }
        }

        return -1;
    }
public:
    int repeatedStringMatch(string a, string b) {
        std::vector<int> pr = prefix_function(b);
        std::string tmp;
        int count = 0;

        while (tmp.size() < b.size()) {
            tmp += a;
            count += 1;
        }

        if (kmp(tmp, b, pr) != -1) {
            return count;
        }

        tmp += a;

        if (kmp(tmp, b, pr) != -1) {
            return count + 1;
        }

        return -1;
    }
};