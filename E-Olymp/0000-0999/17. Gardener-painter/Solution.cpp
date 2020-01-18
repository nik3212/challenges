/*

Gardener has to paint trees after planting. He has paint of three colour: white, blue and orange.

How many ways he can paint of N trees, if not any two the same colours can be side by side?

Input

The quantity of trees is N (1 ≤ N ≤ 50).

Output

The quantity of ways of paint.

*/

#include <iostream>

long long count_of_colors(int n) {
    long long res = 3;

    for (int i = 1; i < n; ++i) {
        res *= 2;
    }

    return res;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << count_of_colors(n) << std::endl;
    return 0;
}
