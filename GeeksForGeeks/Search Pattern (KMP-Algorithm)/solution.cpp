/*

Search Pattern (KMP-Algorithm)

Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

*/

class Solution
{
    private:
        std::vector<int> prefix_function(std::string pattern) {
            int n = pattern.size();
            std::vector<int> v(n, 0);
            
            int k = 0;
            
            for (int i = 1; i < n; ++i) {
                while (k > 0 && pattern[i] != pattern[k]) {
                    k = v[k - 1];
                }
                
                if (pattern[i] == pattern[k]) {
                    k++;
                }
                
                v[i] = k;
            }
            
            return v;
        }
    public:
        vector <int> search(string pat, string txt) {
            std::vector<int> pr = prefix_function(pat);

            int text_len = txt.size();
            int pat_len = pat.size();
            
            std::vector<int> v;
            
            int i = 0;
            int j = 0;
            
            while ((text_len - i) >= (pat_len - j)) {
                if (txt[i] == pat[j]) {
                    i++;
                    j++;
                }
                
                if (j == pat_len) {
                    v.push_back(i - j + 1);
                    j = pr[j - 1];
                } else if (txt[i] != pat[j]) {
                    if (j == 0) {
                        i++;
                    } else {
                        j = pr[j - 1];
                    }
                }
            }
            
            return v;
        }
     
};