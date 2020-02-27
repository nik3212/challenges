/*

A. Theatre Square

time limit per test: 1 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones. Each flagstone is of the size a × a.

What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. The sides of flagstones should be parallel to the sides of the Square.

Input

The input contains three positive integer numbers in the first line: n,  m and a (1 ≤  n, m, a ≤ 10^9).

Output

Write the needed number of flagstones.

*/

#include <iostream>
#include <cmath>

int main() {
    unsigned long long n, m, a;
    std::cin >> n >> m >> a;

    unsigned long long x = std::ceil(1.0 * n / a);
    unsigned long long y = std::ceil(1.0 * m / a);

    std::cout << x * y << std::endl;

    return 0;
}
