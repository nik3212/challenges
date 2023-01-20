/*

796. Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.

*/

class Solution {
private:
    int init_hash(int len, int q, int d) {
        int res = 1;

        for (int i = 0; i < len - 1; ++i) {
            res = (res * d) % q;
        }

        return res;
    }

    int ring_hash(const char *s, int s_len, int prev_hash) {
        int q = 65713;
        int d = 52;

        if (prev_hash == 0) {
            for (int i = 0; i < s_len; ++i) {
                prev_hash = (prev_hash * d + (int)s[i]) % q;
            }
            return prev_hash;
        } else {
            int h = init_hash(s_len, q, d);
            int hash = ((prev_hash - (int)s[0] * h) * d + s[s_len]) % q;
            if (hash < 0) {
                hash += q;
            }
            return hash;
        }
    }
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        std::string text = s + s;

        const char *c_goal = goal.c_str();
        const char *c_text = text.c_str();

        int goal_hash = ring_hash(c_goal, s.size(), 0);
        int s_hash = ring_hash(c_text, s.size(), 0);

        for (int i = 0; i < s.size(); ++i) {
            if (s_hash == goal_hash) {
                for (int j = 0; j < s.size(); ++j) {
                    if (c_goal[j] != c_text[i + j]) {
                        break;
                    }
                }
                return true;
            } else {
                s_hash = ring_hash(&c_text[i], s.size(), s_hash);
            }
        }

        return false;
    }
};