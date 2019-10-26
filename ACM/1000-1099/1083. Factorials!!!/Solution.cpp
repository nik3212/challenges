/*

1083. Factorials!!!

Time limit: 1.0 second
Memory limit: 64 MB

Definition 1. n!!…! = n(n−k)(n−2k)…(n mod k), if k doesn’t divide n; 
n!!…! = n(n−k)(n−2k)…k, if k divides n (There are k marks ! in the both cases).

Definition 2. X mod Y — a remainder after division of X by Y.

For example, 10 mod 3 = 1; 3! = 3·2·1; 10!!! = 10·7·4·1.

Given numbers n and k we have calculated a value of the expression in the first 
definition. Can you do it as well?

Input

contains the only line: one integer n, 1 ≤ n ≤ 10, then exactly one space, then 
k exclamation marks, 1 ≤ k ≤ 20.

Output

contains one number — n!!…! (there are k marks ! here).

*/

#include <iostream>
#include <string>

using ll = long long int;

ll factorial(int n, int f) {
    ll res = 1;
    int i = 0;

	for (int i = 0;; ++i) {
		if ((n % f != 0 && n - i * f < n % f) ||
         	(n % f == 0 && n - i * f == 0))
			break;
		res *= n - i * f;
	}

    return res;
}

int main() {
	int n;
	std::cin >> n;

	std::string factorials;
	std::cin >> factorials;

    std::cout << factorial(n, factorials.size());

	return 0;
}