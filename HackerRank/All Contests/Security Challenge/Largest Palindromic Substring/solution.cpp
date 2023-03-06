/*

Largest Palindromic Substring

Given a string, S, find its largest palindromic substring.

Sample Input

hackerrekcahba

Sample Output

hackerrekcah

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::vector<int> odd(std::string const &s) {
    int n = s.size();
    std::vector<int> d(s.size(), 1);
    
    int l = 0;
    int r = 0;
    
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            d[i] = std::min(d[l + r - i], r - i + 1);
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

std::string longest_palindrome(std::string const& s) {
    std::string new_s;
    
    for (int i = 0; i < s.size(); ++i) {
        new_s += s[i];
        new_s += '#';
    }
    
    std::vector<int> v = odd(new_s);
    
    int index = 0;
    int val = 0;
    
    for (int i = 0; i < v.size(); ++i) {
        if (val < v[i]) {
            val = v[i];
            index = i;
        }
    }
    
    std::string res;
    
    for (int i = index - val + 1; i < index + val; ++i) {
        if (new_s[i] != '#') {
            res += new_s[i];
        }
    }
    
    return res;
}

int main() {
    std::string s;
    std::cin >> s;
    
    std::cout << longest_palindrome(s) << std::endl;
    
    return 0;
}

