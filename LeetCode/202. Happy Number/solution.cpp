/*

202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

*/

class Solution {
private:
    int square_sum(int n) {
        int sum = 0;

        while (n) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        int slow, fast;

        slow = fast = n;

        do {
            slow = square_sum(slow);
            fast = square_sum(fast);
            fast = square_sum(fast);
        } while (slow != fast);

        return (slow == 1) ? 1 : 0;
    }
};