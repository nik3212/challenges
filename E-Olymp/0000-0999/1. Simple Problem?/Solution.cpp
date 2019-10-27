/*

Simple problem?
Program reads two-digit number and prints every digit separately, separated by a space.

Input
One integer from 10 to 99 including.

Output
Two digits separated by a space.

*/

#include <iostream>

int main() {
	int n;
	std::cin >> n;

	std::cout << n / 10 << " " << n % 10 << std::endl;

	return 0;
}