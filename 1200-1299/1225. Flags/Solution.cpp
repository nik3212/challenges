/*

1225. 1225. Flags

Time limit: 1.0 second
Memory limit: 64 MB

On the Day of the Flag of Russia a shop-owner decided to decorate the show-window of his shop with textile stripes of white, blue and red colors. He wants to satisfy the following conditions:
1. Stripes of the same color cannot be placed next to each other.
2. A blue stripe must always be placed between a white and a red or between a red and a white one.
Determine the number of the ways to fulfill his wish.

Input

N, the number of the stripes, 1 ≤ N ≤ 45.

Output

M, the number of the ways to decorate the shop-window.

*/

#include <iostream>
#include <cmath>
#include <vector>

long long count_of_flags(int n) {
    if(n == 0) return 1;
    if(n < 0) return 0;

    std::vector<long long> s(45);
    s[0] = 1;
    s[1] = 1;

    for (int i = 2; i < n; ++i) {
        s[i] = s[i - 2] + s[i - 1];
    }

    return 2 * s[n - 1];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count_of_flags(n) << std::endl;
    return 0;
}