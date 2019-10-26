/*

1014. Product of Digits

Time limit: 1.0 second
Memory limit: 64 MB

Your task is to find the minimal positive integer number Q so that the product of digits of Q is exactly equal to N.

Input

The input contains the single integer number N (0 ≤ N ≤ 10^9).

Output

Your program should print to the output the only number Q. If such a number does not exist print −1.

*/

#include <iostream>

using ll = long long int;

ll digits(ll);

int main() {
    ll n;

    std::cin >> n;
    std::cout << digits(n) << std::endl;

    return 0;
}

ll digits(ll n) {
    if (n == 0) {
        return 10;
    } else if (n == 1) {
        return 1;
    }

    ll q = 0;
    ll p = 1;

    for (ll div = 9; div > 1; --div) {
        while ((n % div) == 0) {
            q += p * div;
            p = p * 10;
            n /= div;
        }
    }

    return (n == 1) ? q : -1;
}