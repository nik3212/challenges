/*

20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;

        std::set<char> chs = { '(', '{', '[' };

        for (int i = 0; i < s.size(); ++i) {
            if (chs.find(s[i]) != chs.end()) {
                st.push(s[i]);
            } else if (!st.empty()) {
                char t = st.top();
                st.pop();

                if ((s[i] == ')' && t == '(') || (s[i] == '}' && t == '{') || (s[i] == ']' && t == '[')) {
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        if (!st.empty()) {
            return false;
        }

        return true;
    }
};