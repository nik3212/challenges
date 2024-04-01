/*

Longest Substring Without Repeat

Given a string s, find the length of the longest substring without repeating characters.

*/

int longestSubstringWithoutRepeat(string s) {
    std::map<char, int> m;

    int j = 0;
    int res = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (m.count(s[i]) > 0) {
            j = std::max(m[s[i]] + 1, j);
        }

        m[s[i]] = i;
        res = std::max(res, i - j + 1);
    }

    return res;
}