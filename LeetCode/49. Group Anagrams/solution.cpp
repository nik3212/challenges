/*

49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

*/

class Solution {
private:
    std::string sort(std::string &s) {
        std::size_t alphabet_size = 26;
        std::vector<int> dp = std::vector<int>(alphabet_size, 0);

        for (auto &c: s) {
            dp[c - 'a']++;
        }

        std::string str;

        for (int i = 0; i < alphabet_size; ++i) {
            str += std::string(dp[i], i + 'a');
        }

        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<std::string, std::vector<std::string>> m;

        for (auto &s: strs) {
            m[sort(s)].push_back(s);
        }

        for (auto &p : m) {
            res.push_back(p.second);
        }

        return res;
    }
};