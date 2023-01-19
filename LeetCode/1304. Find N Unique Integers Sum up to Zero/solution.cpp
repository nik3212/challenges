/*

1304. Find N Unique Integers Sum up to Zero

Given an integer n, return any array containing n unique integers such that they add up to 0.

*/

class Solution {
public:
    vector<int> sumZero(int n) {
        std::vector<int> v = std::vector<int>(n, 0);
        bool is_even = n % 2 == 0;

        for (int i = 1; i < (is_even ? n : (n - 1)); i += 2) {
            v[i - 1] = i;
            v[i] = -i;
        }

        return v;
    }
};