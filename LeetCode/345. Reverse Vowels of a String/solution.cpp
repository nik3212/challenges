/*

345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

*/

class Solution {
private:
    bool is_contains(const std::set<char>& s, char c) {
        return s.find(c) != s.end();
    }
public:
    string reverseVowels(string s) {
        std::set<char> alphabet = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
        std::size_t size = s.size();

        int l = 0;
        int r = s.length() - 1;
        
        while (l <= r) {
            while (l < size && !is_contains(alphabet, s[l])) {
                l++;
            }
            while (r >= 0 && !is_contains(alphabet, s[r])) {
                r--;
            }

            if (l < r) {
                char tmp = s[l];
                s[l] = s[r];
                s[r] = tmp;
            }

            l++;
            r--;
        }

        return s;
    }
};