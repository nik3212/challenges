/*

859. Buddy Strings

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if (n != m) {
            return false;
        }

        std::vector<int> ch1(26, 0);
        std::vector<int> ch2(26, 0);

        int diff = 0;

        for (int i = 0; i < n; ++i) {
            ch1[s[i] - 'a']++;
            ch2[goal[i] - 'a']++;

            if (s[i] != goal[i]) {
                diff++;
            }
        }

        int r = false;

        for (int i = 0; i < 26; ++i) {
            if (ch1[i] != ch2[i]) {
                return false;
            }

            // swap the same chars
            if (ch1[i] > 1) {
                r = true;
            }
        }

        return (diff == 2) || (diff == 0 && r);
    }
};