/*

392. Is Subsequence

Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

*/

class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        if s == t { return true }

        var iterator = s.makeIterator()
        var current: Character? = iterator.next()

        for c in t {
            if c == current {
                current = iterator.next()
            }
        }

        return current == nil
    }
}