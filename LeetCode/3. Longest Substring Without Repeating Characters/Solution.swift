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
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var dict = [Character: Int]()
        var result = 0
        var k = 0

        for (index, char) in s.enumerated() {
            if let value = dict[char] {
                k = max(k, value)
            }

            result = max(result, index - k + 1)
            dict[char] = index + 1
        }

        return result
    }
}