/*

1. A+B

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 2%)

You want to add two integers A and B.

Input

The only line of the input file INPUT.TXT recorded two positive integers, not exceeding 109.

Output

In the only line of the output file OUTPUT.TXT you should print a single integer — the sum of the numbers A and B.

*/

#include <iostream>

int main() {
	int m, n;
    std::cin >> m >> n;
    
    std::cout << m + n << std::endl;
    
    return 0;
}