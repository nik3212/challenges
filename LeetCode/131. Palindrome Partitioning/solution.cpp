/*

131. Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a  palindrome. Return all possible palindrome partitioning of s.

*/

class Solution {
private:
    bool is_palindrome(std::string const& s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }

    void partitions(std::vector<std::vector<std::string>> &v, std::vector<std::string> &curr, std::string const &s) {
        if (s.size() == 0) {
            v.push_back(curr);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            std::string s1 = s.substr(0, i + 1);
            std::string s2 = s.substr(i + 1);

            if (is_palindrome(s1)) {
                curr.push_back(s1);
                partitions(v, curr, s2);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> v;
        std::vector<std::string> curr;

        partitions(v, curr, s);

        return v;
    }
};