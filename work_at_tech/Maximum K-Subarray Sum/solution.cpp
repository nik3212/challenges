/*

Maximum K-Subarray Sum

Given an array and a number k, find the sum of the subarray that has the maximum sum among all the subarrays of size k.

*/

int maxKSubarraySum(vector<int> &A, int k) {
	int res = 0;
	
	for (int i = 0; i < k; ++i) {
		res += A[i];
	}
	
	int curr = res;
	for (int i = k; i < A.size(); ++i) {
		curr = curr + A[i] - A[i - k];
		res = std::max(res, curr);
	}
	
	return res;
}