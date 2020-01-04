/*

Pizza

(Time limit: 1 sec. Memory limit: 16 MB Difficulty: 20%)

Pizza is John's favorite treat, he constantly buys and enjoys various kinds of this gorgeous dish. Once, cutting a round pizza into several pieces, John wondered: what is the maximum number of pieces you can cut a pizza to using N straight cuts?

Help John solve this problem and find the maximum number of not necessarily equal pieces that John can get by cutting a pizza this way.

Input

Input contains one integer N (1 ≤ N ≤ 1000) the number of straight pizza cuts.

Output

Output one integer equal to the maximum number of pieces you can cut a pizza to using N straight cuts.

*/

#include <iostream>
#include <vector>

int count(size_t n) {
    std::vector<int> v(n + 1);

    v[1] = 2;
    v[2] = 4;

    for (size_t i = 3; i <= n; ++i) {
        v[i] = v[i - 1] + i;
    }

    return v[n];
}

int main() {
    size_t n;
    std::cin >> n;

    std::cout << count(n) << std::endl;

    return 0;
}
