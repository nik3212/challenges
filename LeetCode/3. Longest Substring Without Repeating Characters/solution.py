#
# 3. Longest Substring Without Repeating Characters
#
# Given a string, find the length of the longest substring without repeating characters.
#
# Example 1:
#
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
#
# Example 2:
#
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
#
# Example 3:
#
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
#              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

# Complexity
#
# Time complexity: O(n)
# Space complexity: O(n)

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        d = {}
        result = 0
        index = 0
        
        for i in range(0, len(s)):
            if s[i] in d:
                index = max(index, d[s[i]])
                d[s[i]] = i + 1
            else:
                d[s[i]] = i + 1
        
            result = max(result, i - index + 1)
        
        return result