/*

821. Shortest Distance to a Character

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

*/

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        std::vector<int> v;
        std::vector<int> res;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == c) {
                v.push_back(i);
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            int val = INT_MAX;

            for (int j = 0; j < v.size(); ++j) {
                val = std::min(val, std::abs(v[j] - i));
            }

            res.push_back(val);
        }

        return res;
    }
};