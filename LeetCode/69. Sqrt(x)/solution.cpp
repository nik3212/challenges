/*

69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

*/

class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (m == x / m) {
                return m;
            } else if (m > x / m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return r;
    }
};