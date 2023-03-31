/*

Reverse the String

Problem Description

You are given a string A of size N.

Return the string A after reversing the string word by word.

NOTE:

* A sequence of non-space characters constitutes a word.
* Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
* If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

void reverse(std::string& s, int i, int j) {
    while (i < j) {
        char t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
}

void reverse_words(std::string& s, int n) {
    int i = 0;
    int j = 0;
    
    while (i < n) {
        while (i < j || i < n && s[i] == ' ') { i++; }
        while (j < i || j < n && s[j] != ' ') { j++; }
        reverse(s, i, j - 1);
    }
}

std::string clean_spaces(std::string s, int n) {
    int i = 0;
    int j = 0;
    
    while (j < n) {
        while (j < n && s[j] == ' ') { j++; }
        while (j < n && s[j] != ' ') { s[i++] = s[j++]; };
        while (j < n && s[j] == ' ') { j++; }
        if (j < n) { s[i++] = ' '; }
    }
    
    return s.substr(0, i);
}

string Solution::solve(string A) {
    int n = A.size();
    
    reverse(A, 0, n - 1);
    reverse_words(A, n);
    
    return clean_spaces(A, n);
}
