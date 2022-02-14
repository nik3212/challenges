/*

784. Letter Case Permutation

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

*/

class Solution {
    std::vector<string> res;

    void helper(std::string& s, int i) {
        if (i >= s.size()) {
            res.push_back(s);
            return;
        }

        if (isdigit(s[i])) {
            helper(s, i + 1);
        } else {
            s[i] = tolower(s[i]);
            helper(s, i + 1);
            s[i] = toupper(s[i]);
            helper(s, i + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return res;
    }
};