/*

Merge Two Sorted Arrays

Given two sorted arrays A and B, find the merged sorted array C by merging A and B.

*/

vector<int> mergeSortedArrays(vector<int> &A, vector<int> B) {
    int p1 = 0;
	int p2 = 0;
	
	int N = A.size();
	int M = B.size();
	
	std::vector<int> v(N + M, 0);
	
	int curr = 0;
	
	while (p1 < N && p2 < M) {
		if (A[p1] < B[p2]) {
			v[curr++] = A[p1++];
		} else {
			v[curr++] = B[p2++];
		}
	}
	
	while (p1 < N) {
		v[curr++] = A[p1++];
	}
	
	while (p2 < M) {
		v[curr++] = B[p2++];
	}
	
	return v;
}