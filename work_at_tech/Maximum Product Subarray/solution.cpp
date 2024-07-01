/*

Maximum Product Subarray

Given an array A of integers, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

Note: The product fits in a 32-bit integer.

*/

int maxProduct(vector<int> &A) {
    int res = A[0];

	int min_n = res;
	int max_n = res;
	
	for (int i = 1; i < A.size(); ++i) {
		if (A[i] < 0) {
			std::swap(min_n, max_n);
		}
		
		max_n = std::max(A[i], max_n * A[i]);
		min_n = std::min(A[i], min_n * A[i]);
		
		res = std::max(max_n, res);
	}
	
	return res;
}