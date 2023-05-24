/*

Implement strstr

Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

*/

std::vector<int> prefix_function(std::string s) {
    std::vector<int> v(s.size(), 0);
    int k = 0;
    
    for (int i = 1; i < s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) {
            k = v[k - 1];
        }
        
        if (s[i] == s[k]) {
            k++;
        }
        
        v[i] = k;
     }
    
    return v;
}

int kmp(std::string text, std::string pattern) {
    int text_len = text.size();
    int pattern_len = pattern.size();
    
    int i = 0;
    int j = 0;
    
    auto pr = prefix_function(pattern);
    
    while ((text_len - i) >= (pattern_len - j)) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        
        if (j == pattern_len) {
            return i - j;
        } else if (text[i] != pattern[j]) {
            if (j == 0) {
                i++;
            } else {
                j = pr[j - 1];
            }
        }
    }
    
    return -1;
}

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x) {
     return kmp(s, x);
}