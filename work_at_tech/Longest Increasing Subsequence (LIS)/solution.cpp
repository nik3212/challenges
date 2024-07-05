/*

Longest Increasing Subsequence (LIS)

Given an array A, find the length of the longest strictly increasing subsequence (LIS).

A subsequence is a sequence that can be derived from an array by deleting some or no elements such that the order of the remaining elements remain the same.

*/

int getLengthOfLIS(vector<int> &A) {
    std::vector<int> v;
	
	v.push_back(A[0]);
	
	for (int i = 1; i < A.size(); ++i) {
		if (A[i] > v.back()) {
			v.push_back(A[i]);
		} else {
			int l = std::lower_bound(v.begin(), v.end(), A[i]) - v.begin();
			v[l] = A[i];
		}
	}
	
	return v.size();
}