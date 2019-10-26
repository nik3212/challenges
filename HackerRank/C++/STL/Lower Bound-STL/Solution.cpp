/*

You are given N integers in sorted order. Also, you are given Q queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.

Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by Clicking Here.

Input Format

The first line of the input contains the number of integers N. The next line contains N integers in sorted order. The next line contains Q, the number of queries. Then Q lines follow each containing a single integer Y.

Note that if the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Constraints

1 <= N <= 10^5
1 <= X_i <= 10^9,where X is i_th element in the array.
1 <= Q <= 10^5
1 <= Y <= 10^9

Output Format

For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.

If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.

You have to output each query in a new line.

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
 
Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find(std::vector<int>& vec, int key) {
    int l = -1;
    int r = vec.size();

    while (l < r - 1) {
        int m = (l + r) / 2;

        if (vec[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }

    return r;
}

int main() {
    int k;
    std::cin >> k;

    std::vector<int> vec(k);

    for (int i = 0; i < k; ++i) {
        std::cin >> vec[i];
    }

    int q;
    std::cin >> q;

    while (q--) {
        int x;
        std::cin >> x;

        auto it = lower_bound(vec.begin(), vec.end(), x);
        std::cout << (*it == x ? "Yes " : "No ") << it - vec.begin() + 1 << std::endl;
    }

    return 0;
}
