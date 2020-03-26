/*

The Fibonacci Sequence

The Fibonacci sequence appears in nature all around us, in the arrangement of seeds in a sunflower and the spiral of a nautilus for example.

The Fibonacci sequence begins with fibinacci(0) = 0 and fibonacci(1) = 1 as its first and second terms. After these first two elements, each subsequent element is equal to the sum of the previous two elements.

Programmatically:

* fibonacci(0) = 0
* fibonacci(1) = 1
* fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)

Given n, return the n^th number in the sequence.

As an example, n = 5. The Fibonacci sequence to 6 is [0, 1, 1, 2, 3, 5, 8]. With zero-based indexing, fs[5] = 5.

Function Description

Complete the recursive function fibonacci in the editor below. It must return the n^th element in the Fibonacci sequence.

fibonacci has the following parameter(s):

* n: the integer index of the sequence to return

Input Format

The input line contains a single integer, n.

Constraints

* 0 <= n <= 30

Output Format

Locked stub code in the editor prints the integer value returned by the fibonacci function.

*/

#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    int a = 0;
    int b = 1;
    int res = 0;

    for (int i = 2; i <= n; ++i) {
        res = a + b;
        a = b;
        b = res;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}