/*

2696. Minimum String Length After Removing Substrings

You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.

*/

class Solution {
public:
    int minLength(string s) {
        std::stack<char> stack;

        for (auto x: s) {
            if (!stack.empty() && ((stack.top() == 'A' && x == 'B') || (stack.top() == 'C' && x == 'D'))) {
                stack.pop();
            } else {
                stack.push(x);
            }
        }

        return stack.size();
    }
};