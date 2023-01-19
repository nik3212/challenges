/*

279. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

*/

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> v = std::vector<int>(n + 1, 100000);

        v[0] = 0;

        for (int i = 1; i < v.size(); ++i) {
            for (int j = 1; j * j <= i; ++j) {
                v[i] = std::min(v[i], v[i - j * j] + 1);
            }
        }

        return v[n];
    }
};