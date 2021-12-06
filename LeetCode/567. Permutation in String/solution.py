#
# 567. Permutation in String
#
# Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
#
# In other words, return true if one of s1's permutations is the substring of s2.
#

#
# Complexity
#
# Time complexity: O(len(s1) + 26 * (len(s2) - len(s1)))
# Space complexity: O(1)
#

class Solution:
    def equal(self, v1, v2) -> bool:
        for i in range(0, 26):
            if (v1[i] != v2[i]):
                return False
        return True

    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        v1 = [0 for _ in range(26)]
        v2 = [0 for _ in range(26)]
        
        for i in range(0, len(s1)):
            v1[ord(s1[i]) - ord('a')] += 1
            v2[ord(s2[i]) - ord('a')] += 1
        
        for i in range(0, len(s2) - len(s1)):
            if self.equal(v1, v2):
                return True
            v2[ord(s2[i]) - ord('a')] -= 1
            v2[ord(s2[i + len(s1)]) - ord('a')] += 1
        
        return self.equal(v1, v2)