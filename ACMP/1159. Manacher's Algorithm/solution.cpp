/*

1159. Manacher's Algorithm

A string is called a palindrome if it is read equally from left to right and from right to left. For example, the strings "abba" and "ata" are palindromes.

A substring of some string is a nonempty sequence of consecutive characters in the original string.

Find out how many substrings of a given string are palindromes.

*/

#include <iostream>
#include <vector>
#include <string>
 
std::vector<int> odd(std::string &s) {
    int n = s.size();
 
    std::vector<int> d(n, 1);
 
    int l = 0;
    int r = 0;
 
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            d[i] = std::min(r - i + 1, d[l + r - i]);
        }
         
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]) {
            d[i]++;
        }
         
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }
 
    return d;
}
 
std::vector<int> even(std::string &s) {
    int n = s.size();
 
    std::vector<int> d(n, 0);
 
    int l = -1;
    int r = -1;
 
    for (int i = 0; i < n - 1; ++i) {
        if (i < r) {
            d[i] = std::min(r - i, d[l + r - i - 1]);
        }
         
        while (i - d[i] >= 0 && i + d[i] + 1 < n && s[i - d[i]] == s[i + d[i] + 1]) {
            d[i]++;
        }
         
        if (i + d[i] > r) {
            l = i - d[i] + 1;
            r = i + d[i];
        }
    }
 
    return d;
}
 
int main() {
    std::string s;
    std::cin >> s;
 
    if (s.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }
 
    std::vector<int> o = odd(s);
    std::vector<int> e = even(s);
     
    uint64_t r = 0;
     
    for (int i = 0; i < s.size(); ++i) {
        r += o[i] + e[i];
    }
     
    std::cout << r << std::endl;
     
    return 0;
}