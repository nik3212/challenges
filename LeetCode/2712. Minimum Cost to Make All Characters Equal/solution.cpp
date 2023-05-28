/*

2712. Minimum Cost to Make All Characters Equal

You are given a 0-indexed binary string s of length n on which you can apply two types of operations:

Choose an index i and invert all characters from index 0 to index i (both inclusive), with a cost of i + 1
Choose an index i and invert all characters from index i to index n - 1 (both inclusive), with a cost of n - i
Return the minimum cost to make all characters of the string equal.

Invert a character means if its value is '0' it becomes '1' and vice-versa.

*/

class Solution {
public:
    long long minimumCost(string s) {
        long long res = 0;
        int n = s.size();

        for (int i = 1; i < n; ++i) {
            if (s[i - 1] != s[i]) {
                res += std::min(i, n - i);
            }
        }

        return res;
    }
};