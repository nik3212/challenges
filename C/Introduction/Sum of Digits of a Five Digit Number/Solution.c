/*

Objective

In order to get the last digit of a number, we use modulo operator \%. When the number is modulo divided by 10 we get the last digit.

To find first digit of a number we divide the given number by 10 until number is greater than 10. At the end we are left with the first digit.

Task

In this challenge, you have to input a five digit number and print the sum of digits of the number.

Input Format

The input contains a single five digit number, n.

Constraints

10000 <= n <= 99999

Output Format

Print the sum of the digits of the five digit number.

Sample Input 0

10564

Sample Output 0

16

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    scanf("%d", &n);
    
    int res = 0;

    while (n) {
        res += n % 10;
        n /= 10;
    }

    printf("%d", res);

    return 0;
}
