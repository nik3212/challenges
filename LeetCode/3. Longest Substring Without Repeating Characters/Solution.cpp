/*

3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        std::map<char, int> map;

        int result = 0;
        int k = 0;

        for (int i = 0; i < size; ++i) {
            auto it = map.find(s[i]);

            if (it != map.end()) {
                k = std::max(it->second, k);
                it->second = i + 1;
            } else {
                map.insert(std::make_pair(s[i], i + 1));
            }

            result = std::max(result, i - k + 1);
        }

        return result;
    }
};