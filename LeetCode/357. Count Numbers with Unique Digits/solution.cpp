/*

357. Count Numbers with Unique Digits

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 10;
        int cal = 9;
        int tmp = 9;

        for (int i = 0; i < n - 1; ++i) {
            cal *= tmp;
            ans += cal;
            tmp--;
        }

        return ans;
    }
};