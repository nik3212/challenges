/*

 1001. Reverse Root

Time limit: 2.0 second
Memory limit: 64 MB

The problem is so easy, that the authors were lazy to write a statement for it!

Input

The input stream contains a set of integer numbers Ai (0 ≤ Ai ≤ 10^18). The numbers are separated by 
any number of spaces and line breaks. A size of the input stream does not exceed 256 KB.

Output

For each number Ai from the last one till the first one you should output its square root. Each square 
root should be printed in a separate line with at least four digits after decimal point.

 */

int main() {
	unsigned long long value;

	std::vector<unsigned long long> values;

	while (std::cin >> value) {
		values.push_back(value);
	}

	std::cout.setf(std::ios::fixed);
	std::setprecision(4);

	for (int i = values.size() - 1; i >= 0; i--) {
		std::cout << std::sqrt(values[i]) << std::endl;
	}

	return 0;
}