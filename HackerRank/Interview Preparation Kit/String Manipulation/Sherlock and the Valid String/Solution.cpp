/*

Sherlock considers a string to be valid if all characters of the string appear the same number of times. It is also valid if he can remove just 1 character at 1 index in the string, and the remaining characters will occur the same number of times. Given a string s, determine if it is valid. If so, return YES, otherwise return NO.

For example, if s = abc, it is a valid string because frequencies are { a: 1, b: 1, c: 1 }. So is s = abcc because we can remove one c and have 1 of each character in the remaining string. If s = abccc however, the string is not valid as we can only remove occurrence of c. That would leave character frequencies of { a: 1, b: 1, c: 2 }.

Function Description

Complete the isValid function in the editor below. It should return either the string YES or the string NO.

isValid has the following parameter(s):

s: a string

Input Format

A single string s.

Constraints

1 <= |s| <= 10^5
Each character s[i] ∈ ascii[a-z]

Output Format

Print YES if string s is valid, otherwise, print NO.

Sample Input 0

aabbcd

Sample Output 0

NO

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    if (s.size() == 0) { return "NO"; }
    if (s.size() <= 3) { return "YES"; }

    std::vector<int> v(26);

    for (int i = 0; i < s.size(); ++i) {
        v[s[i] - 'a']++;
    }

    sort(v.begin(), v.end());

    int k = 0;

    while (v[k] == 0) {
        k++;
    }

    int min = v[k];
    int max = v[25];

    if (min == max) {
        return "YES";
    }

    if ((max - min == 1 && max > v[24]) || ((min == 1) && v[k + 1] == max)) {
        return "YES";
    }

    return "NO";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
