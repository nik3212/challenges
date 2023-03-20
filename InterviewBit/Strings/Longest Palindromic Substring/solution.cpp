/*

Longest Palindromic Substring.

Problem Description


Given a string A of size N, find and return the longest palindromic substring in A.

Substring of string A is A[i...j] where 0 <= i <= j < len(A)

Palindrome string:


A string which reads the same backwards. More formally, A is palindrome if reverse(A) = A.

Incase of conflict, return the substring which occurs first ( with the least starting index).

Problem Constraints


1 <= N <= 6000 

Input Format


First and only argument is a string A.

Output Format


Return a string denoting the longest palindromic substring of string A.

*/

std::vector<int> odd(std::string const &s) {
    int n = s.size();

    std::vector<int> d(n, 1);
    
    int l = 0;
    int r = 0;
    
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            d[i] = std::min(d[r + l - i], r - i);
        }
        
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]]) {
            d[i]++;
        }
        
        if (i + d[i] - 1 > n) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
    }
    
    return d;
}

string Solution::longestPalindrome(string A) {
    std::string s;
    
    for (int i = 0; i < A.size(); ++i) {
        s += '#';
        s += A[i];
    }
    s += '#';
    
    std::vector<int> v = odd(s);

    int index = 0;
    int m = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (m < v[i]) {
            index = i;
            m = v[i];
        }
    }

    std::string res;

    for (int i = index - m + 1; i < index + m; ++i) {
        if (s[i] != '#') {
            res += s[i];
        }
    }
    
    return res;
}
