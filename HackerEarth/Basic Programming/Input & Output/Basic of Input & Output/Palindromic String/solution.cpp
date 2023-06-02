/*

Palindromic String

Problem
You have been given a String S. You need to find and print whether this string is a palindrome or not. If yes, print "YES" (without quotes), else print "NO" (without quotes).

Input Format
The first and only line of input contains the String S. The String shall consist of lowercase English alphabets only.

Output Format
Print the required answer on a single line.

*/

#include <iostream>
#include <string>

bool is_palindrome(std::string &s) {
	int i = 0;
	int j = s.size() - 1;

	while (i < j) {
		if (s[i++] != s[j--]) {
			return false;
		}
	}

	return true;
}

int main(){
	std::string s;
	std::cin >> s;

	bool res = is_palindrome(s);

	std::cout << (res ? "YES" : "NO") << std::endl;

	return 0;
}
