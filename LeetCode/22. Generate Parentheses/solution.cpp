/*

22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

*/

class Solution {
    void backtrack(std::vector<string> &s, std::string &cur, int start, int end, int n) {
        if (cur.size() == 2 * n) {
            s.push_back(cur);
            return;
        }

        if (start < n) {
            cur.push_back('(');
            backtrack(s, cur, start + 1, end, n);
            cur.pop_back();
        }

        if (end < start) {
            cur.push_back(')');
            backtrack(s, cur, start, end + 1, n);
            cur.pop_back();
        }
    } 
public:
    vector<string> generateParenthesis(int n) {
        std::string tmp;
        std::vector<string> s;
        backtrack(s, tmp, 0, 0, n);
        return s;
    }
};