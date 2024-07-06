/*

Trailing Zeroes

Given a number, let's say, 102000. Can you count how many zeroes are present at the end of the number?

In this case, it is 3. The zeroes at the end of a number are known as trailing zeroes.

Trailing zeroes are a sequence of zeroes in a number after which there are no other digits.

Examples
trailingZeroes(120) → 1
trailingZeroes(1300) → 2
trailingZeroes(123400) → 2
trailingZeroes(1000) → 3
trailingZeroes(102000) → 3

The factorial of a number ‘n’ is the product of all the numbers from 1 to n.

Example
factorial(5) → 1*2*3*4*5 → 120
factorial(1) → 1

Note that factorial(0) is also 1.

Given a number ‘n’, find the no of trailing zeroes in the factorial of ‘n’.

trailingZeroesInFactorial(10) → 2

*/

int trailingZeroesInFactorial(int n) {
	int r = 0;
	
	while (n) {
		r += n /= 5;
	}
	
	return r;
}
