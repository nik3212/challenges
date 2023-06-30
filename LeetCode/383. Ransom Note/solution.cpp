/*

383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> v(26, 0);

        for (int i = 0; i < magazine.size(); ++i) {
            v[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); ++i) {
            if (v[ransomNote[i] - 'a'] == 0) {
                return false;
            }
            v[ransomNote[i] - 'a']--;
        }

        return true;
    }
};