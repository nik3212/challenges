/*

17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

*/

class Solution {
private:
    void backtrack(std::map<char, std::string> const &m, std::string const &digits, int pos, std::string &curr, std::vector<string> &result) {
        if (curr.size() == digits.size()) {
            result.push_back(curr);
            return;
        }

        auto it = m.find(digits[pos]);
        std::string val = it->second;

        for (int i = 0; i < val.size(); ++i) {
            curr.push_back(val[i]);
            backtrack(m, digits, pos + 1, curr, result);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        std::string curr;
        std::vector<std::string> result;

        if (digits.size() == 0) {
            return result;
        }

        std::map<char, std::string> m {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" },
        };

        backtrack(m, digits, 0, curr, result);
    
        return result;
    }
};