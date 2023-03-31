/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();

        for (int i = 1; i < strs.size(); ++i) {
            int j = 0;

            while (j < strs[0].size() && j < strs[i].size() && strs[i][j] == strs[0][j]) {
                j++;
            }

            len = std::min(len, j);
        }

        return strs[0].substr(0, len);
    }
};