/*

30. Substring with Concatenation of All Words

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

*/

class Solution {
private:
    bool check(std::string s, std::unordered_map<std::string, int> m, int index, int word_size) {
        for (int i = 0; i < s.size(); i += word_size) {
            std::string w = s.substr(i, word_size);

            if (m.count(w) != 0) {
                if (--m[w] == -1) { return false; }
            } else { return false; }
        }

        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_size = words[0].size();
        int n = words.size() * word_size;
        int size = s.size();

        std::unordered_map<std::string, int> w;
        std::vector<int> res;

        for (int i = 0; i < words.size(); ++i) {
            w[words[i]]++;
        }

        int i = 0;

        while (i + n <= size) {
            if (check(s.substr(i, n), w, i, word_size)) { res.push_back(i); };
            i++;
        }

        return res;
    }
};