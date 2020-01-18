/*

608. Gardener-Artist

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 28%)

The gardener has planted N trees in one row. Now the gardener wants to paint each of them in one of the three colors: white, blue or orange. Also, no two neighboring trees should be painted in the same color.

Find out the number of ways to paint the trees.

Input

Input contains one integer N (1 ≤ N ≤ 50) the number of trees.

Output

Output one integer equal to the number of ways to paint the trees.

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
