/*

String Inversion

Problem Description

Given a string A. Change the cases of all the characters.
If the character is lowercase convert it to uppercase and if the character is uppercase convert it to lowercase.

Note: All the characters in the string are latin uppercase or lowercase letters.

*/

bool is_capital(char x) {
       if (x >='A' && x <= 'Z') return true;
       else return false;
}

string Solution::solve(string A) {
    std::string res;
    
    for (int i = 0; i < A.size(); ++i) {
        if (is_capital(A[i])) {
            res += tolower(A[i]);
        } else {
            res += toupper(A[i]);
        }
    }
    
    return res;
}
