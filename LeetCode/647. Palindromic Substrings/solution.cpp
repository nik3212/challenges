/*

647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

*/

class Solution {
private:
    std::vector<int> even(std::string s) {
        int n = s.size();
        std::vector<int> d(n, 0);

        int l = -1;
        int r = -1;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (i < r) {
                d[i] = std::min(d[r + l - i - 1], r - i);
            }

            while (i - d[i] >= 0 && i + d[i] + 1 < s.size() && s[i - d[i]] == s[i + d[i] + 1]) {
                d[i]++;
            }

            if (i + d[i] + 1 > r) {
                l = i - d[i] + 1;
                r = i + d[i];
            }
        }

        return d;
    }

    std::vector<int> odd(std::string s) {
        int n = s.size();
        std::vector<int> d(n, 1);

        int l = 0;
        int r = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (i < r) {
                d[i] = std::min(d[l + r - i], r - i + 1);
            }

            while (i - d[i] >= 0 && i + d[i] < s.size() && s[i - d[i]] == s[i + d[i]]) {
                d[i]++;
            }

            if (i + d[i] - 1 > r) {
                l = i - d[i] + 1;
                r = i + d[i] - 1;
            }
        }

        return d;
    }
public:
    int countSubstrings(string s) {
        std::vector<int> v1 = even(s);
        std::vector<int> v2 = odd(s);

        int sum = 0;

        for (int i = 0; i < s.size(); ++i) {
            sum += v1[i] + v2[i];
        }

        return sum;
    }
};