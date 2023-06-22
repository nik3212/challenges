/*

2000. Reverse Prefix of Word

Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string.

*/

class Solution {
private:
    void reverse(std::string &word, int s, int e) {
        while (s < e) {
            std::swap(word[s++], word[e--]);
        }
    }
public:
    string reversePrefix(string word, char ch) {
        int e = 0;

        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                e = i;
                break;
            }
        }

        reverse(word, 0, e);

        return word;
    }
};