/*

C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

Declaration:

string a = "abc";

Size:

int len = a.size();

Concatenate two strings:

string a = "abc";
string b = "def";
string c = a + b; // c = "abcdef".

Accessing i_th element:

string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'

s[0] = 'z';         // s = "zbc"
P.S.: We will use cin/cout to read/write a string.

Input Format

You are given two strings, a and b, separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of  and  respectively. 
In the second line print the string produced by concatenating a and b (a + b). 
In the third line print two strings separated by a space, a' and b'. a' and b' are the same as a and b, respectively, except that their first characters are swapped.

Sample Input

abcd
ef

Sample Output

4 2
abcdef
ebcd af

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string a, b;
    std::cin >> a >> b;

    std::cout << a.size() << " " << b.size() << std::endl;
    std::cout << a + b << std::endl;

    char ch = a[0];
    a[0] = b[0];
    b[0] = ch;

    std::cout << a << " " << b << std::endl;

    return 0;
}