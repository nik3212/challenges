/*

Longest Increasing Subsequence

Problem Description

Find the longest increasing subsequence of a given array of integers, A.
In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, and in which the subsequence is as long as possible.
In this case, return the length of the longest increasing subsequence.

Problem Constraints

1 <= length(A) <= 2500
0 <= A[i] <= 2500

Input Format
The first and the only argument is an integer array A.

Output Format
Return an integer representing the length of the longest increasing subsequence.

*/

int Solution::lis(const vector<int> &v) {
    int n = v.size();
	std::vector<int> r;

	r.push_back(v[0]);

	for (int i = 1; i < n; ++i) {
		if (v[i] > r.back()) {
			r.push_back(v[i]);
		} else {
			int low = std::lower_bound(r.begin(), r.end(), v[i]) - r.begin();
			r[low] = v[i];
		}
	}	

	return r.size();
}
