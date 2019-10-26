/*

A for loop is a programming language statement which allows code to be repeatedly executed.

The syntax for this is

for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>

expression_1 is used for intializing variables which are generally used for controlling terminating flag for the loop.
expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
expression_3 is generally used to update the flags/variables.

A sample loop will be

for(int i = 0; i < 10; i++) {
    ...
}

Input Format

You will be given two positive integers, a and  (a <= b), separated by a newline.

Output Format

For each integer  in the interval [a, b]:

If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

Sample Input

8
11

Sample Output

eight
nine
even
odd

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n1, n2;
    std::cin >> n1 >> n2;

        string num[11] = { "even", "odd", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    for (int i = n1; i <= n2; ++i) {
        if ((i > 9) && (i % 2 == 0)) {
            std::cout << num[0] << std::endl;
        } else if ((i > 9) && (i % 2 != 0)) {
            std::cout << num[1] << std::endl;
        } else {
            std::cout << num[i + 1] << std::endl;
        }
    }

    return 0;
}