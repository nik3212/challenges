/*

567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

*/

/*

Complexity

Time complexity: O(len(s1) + 26 * (len(s2) - len(s1)))
Space complexity: O(1)

*/

class Solution {
private:
    bool equal(std::vector<int> v1, std::vector<int> v2) {
        for (int i = 0; i < 26; ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        std::vector<int> v1 = std::vector<int>(26, 0);
        std::vector<int> v2 = std::vector<int>(26, 0);

        for (int i = 0; i < s1.size(); ++i) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2.size() - s1.size(); ++i) {
            if (equal(v1, v2)) {
                return true;
            }
            v2[s2[i] - 'a']--;
            v2[s2[i + s1.size()] - 'a']++;
        }

        return equal(v1, v2);
    }
};