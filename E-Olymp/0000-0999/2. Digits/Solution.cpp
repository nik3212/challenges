/*

Digits

Find the number of digits in a nonnegative integer n.

Input

One nonnegative integer n (0 ≤ n ≤ 2 *10^9).

Output

Print the number of digits in number n.

*/

#include <iostream>

int count_of_numbers(unsigned long n) {
    if (n == 0) {
        return 1;
    }

    int count = 0;

    while (n) {
        count++;
        n /= 10;
    }

    return count;
}

int main() {
    unsigned long n;
    std::cin >> n;

    std::cout << count_of_numbers(n) << std::endl;

    return 0;
}