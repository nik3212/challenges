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

#include <iostream>
#include <string>
#include <cmath>

int makeAnagram(std::string a, std::string b) {
    int s1[26] = {};
    int s2[26] = {};

    for (auto it = a.begin(); it != a.end(); ++it) {
        s1[*it - 'a']++;
    }

    for (auto it = b.begin(); it != b.end(); ++it) {
        s2[*it - 'a']++;
    }

    int sum = 0;
    for (int i = 0; i < 26; ++i) {
        sum += std::abs(s1[i] - s2[i]);
    }

    return sum;
}

int main() {
    std::string s1;
    std::cin >> s1;

    std::string s2;
    std::cin >> s2;

    std::cout << makeAnagram(s1, s2) << std::endl;

    return 0;
}