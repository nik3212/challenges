/*

Search Pattern (Z-algorithm)

Given two strings, one is a text string and the other is a pattern string. The task is to print the indexes of all the occurrences of the pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

*/

class Solution
{
    private:
        std::vector<int> z_function(std::string const &s) {
            std::vector<int> z = std::vector<int>(s.size(), 0);
    
            for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
                if (i <= r) {
                    z[i] = std::min(z[i - l], r - i + 1);
                }
    
                while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {
                    z[i]++;
                }
    
                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1;
                }
            }
    
            return z;
        }
    public:
        vector <int> search(string pat, string txt) {
            std::string c = pat + "#" + txt;
            std::vector<int> z = z_function(c);
            std::vector<int> res;
            
            for (int i = 0; i < c.size(); ++i) {
                if (z[i] == pat.size()) {
                    res.push_back(i - pat.size());
                }
            }
            
            return res;
        }
     
};