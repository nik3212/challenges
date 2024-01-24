/*

50. Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

*/

class Solution {
public:
    double myPow(double x, int n) {
        double p = 1;

        while (n) {
            if (n % 2) {
                if (n > 0) {
                    p *= x;
                } else {
                    p /= x;
                }
            }
            

            x *= x;
            n /= 2;
        }

        return p;
    }
};