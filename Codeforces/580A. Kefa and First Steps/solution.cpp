/*

A. Kefa and First Steps

time limit per test: 2 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output

Kefa decided to make some money doing business on the Internet for exactly n days. He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!

Input

The first line contains integer n (1 ≤ n ≤ 105).

The second line contains n integers a1,  a2,  ...,  an (1 ≤ ai ≤ 109).

Output

Print a single integer — the length of the maximum non-decreasing subsegment of sequence a.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int max_sequence(std::vector<int>& v) {
    if (v.size() == 0) { return 0; }

    int count = 1;
    int current = 1;

    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i - 1] <= v[i]) {
            current += 1;
        } else {
            if (count < current) {
                count = current;
            }

            current = 1;
        }
    }

    count = std::max(count, current);

    return count;
}

int main() {
    size_t count;
    std::cin >> count;

    std::vector<int> v(count);

    for (size_t i = 0; i < count; ++i) {
        std::cin >> v[i];
    }

    std::cout << max_sequence(v) << std::endl;

    return 0;
}