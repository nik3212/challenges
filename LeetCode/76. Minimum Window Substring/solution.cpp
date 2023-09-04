/*

76. Minimum Window Substring

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (m > n) { return ""; }

        std::vector<int> mt(256, 0);
        std::vector<int> window(256, 0);

        for (int i = 0; i < m; ++i) {
            mt[t[i]]++;
        }

        int count = 0;
        int start = -1;
        int end = -1;
        int j = 0;
        int len = INT_MAX;

        for (int i = 0; i < s.size(); ++i) {
            window[s[i]]++;

            if (window[s[i]] <= mt[s[i]]) {
                count++;
            }

            if (count == m) {
                while (mt[s[j]] == 0 || window[s[j]] > mt[s[j]]) {
                    window[s[j]]--;
                    j++;
                }

                if (i - j + 1 < len) {
                    len = i - j + 1;
                    start = j;
                    end = i;
                }

                window[s[j]]--;
                j++;
                count--;
            }
        }

        if (start == -1) { return ""; }

        std::string f;

        for (int i = start; i <= end; ++i) {
            f += s[i];
        }

        return f;
    }
};