/*

1068. Sum

Time limit: 2.0 second
Memory limit: 64 MB

Your task is to find the sum of all integer numbers lying between 1 and N inclusive.

Input

The input consists of a single integer N that is not greater than 10000 by it's absolute value.

Output

Write a single integer number that is the sum of all integer numbers lying between 1 and N inclusive.

*/

#include <iostream>

int sum(int n) {
	return (n > 1) ? n * (n + 1) / 2 : (-(-n)*(1 - n) / 2 + 1); 
}

int main() {
	int value;
	std::cin >> value;

	std::cout << sum(value) << std::endl;

	return 0;
}