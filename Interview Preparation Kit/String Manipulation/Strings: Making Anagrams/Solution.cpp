/*

Alice is taking a cryptography class and finding anagrams to be very useful. 
We consider two strings to be anagrams of each other if the first string's letters can be rearranged 
to form the second string. In other words, both strings must contain the same exact letters in the same 
exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice decides on an encryption scheme involving two large strings where encryption is dependent on the 
minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character 
deletions required to make and anagrams. Any characters can be deleted from either of the strings.

For example, if a = cde and b = dcf, we can delete e from string a and f from string b so that both remaining strings 
are cd and dc which are anagrams.

Input Format

The first line contains a single string, a.
The second line contains a single string, b.

Constraints
  
* 1 <= |a|,|b| <= 10^4
* It is guaranteed that and consist of lowercase English alphabetic letters (i.e., a through z).

Output Format

Print a single integer denoting the number of characters you must delete to make the two strings 
anagrams of each other.

Sample Input

cde
abc

Sample Output

4

*/

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    std::vector<int> s1(26);
    std::vector<int> s2(26);

    for (int i = 0; i < a.size(); ++i) {
        s1[a[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); ++i) {
        s2[b[i] - 'a']++;
    }

    int res = 0;

    for (int i = 0; i < 26; ++i) {
        res += std::abs(s1[i] - s2[i]);
    }

    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
