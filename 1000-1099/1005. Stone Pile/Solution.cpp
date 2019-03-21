/*

1005. Stone Pile

Time limit: 1.0 second
Memory limit: 64 MB

You have a number of stones with known weights w1, …, wn. Write a program that will rearrange the stones into two piles 
such that weight difference between the piles is minimal.

Input

Input contains the number of stones n (1 ≤ n ≤ 20) and weights of the stones w1, …, wn (integers, 1 ≤ wi ≤ 100000) 
delimited by white spaces.

Output

Your program should output a number representing the minimal possible weight difference between stone piles.

*/

#include <iostream>
#include <vector>

int f(size_t i, int a, int s, std::vector<int>& m) {
    return i < m.size() ? std::min(f(i + 1, a, s, m), f(i + 1, a + m[i], s, m)) : abs(2 * a - s);
}

int main() {
    size_t n;
    std::cin >> n;

    std::vector<int> w(n);

    for (size_t i = 0; i < n; ++i) {
        std::cin >> w[i];
    }

    int s = 0;

    for (auto& n : w) {
        s += n;
    }

    std::cout << f(0, 0, s, w) << std::endl;

    return 0;
}
