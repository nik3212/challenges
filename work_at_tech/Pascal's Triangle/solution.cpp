/*

Pascal's Triangle

The triangle below is known as Pascal’s triangle.
In this triangle, the value at a position is equal to the sum of values of the 2 elements just above it.

For the leftmost and the rightmost position in each row, the value is 1. The element in the first row is also 1.

Given a number n, find the nth row of pascal’s triangle.

*/

vector<int> pascalTriangleRow(int rowNo) {
	std::vector<std::vector<int>> v(rowNo);
	
	if (rowNo == 0) {
		return std::vector<int>();
	}
	
    v[0] = {1};

    if (rowNo > 1) {
        v[1] = {1, 1};
    }
	
	for (int i = 2; i < rowNo; ++i) {
		v[i].push_back(1);
		
		for (int j = 1; j < i; ++j) {
			v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]);
		}
		
		v[i].push_back(1);
	}
	
	return v[rowNo - 1];
}