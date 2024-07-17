/*

Distinct Numbers in Window

Given an array A and a value k, find the number of distinct elements in each window (subarray) of size k.

*/

vector<int> distintNumbersInWindow(vector<int> &A, int k) {
    std::vector<int> dp(A.size() - k + 1);
	std::unordered_map<int, int> m;

	int curr = 0;

	for (int i = 0; i < A.size(); ++i) {
		if (m[A[i]]++ == 0) {
			curr++;
		}
		
		if (i >= k) {
			if (--m[A[i - k]] == 0) {
				curr--;
			}
		}
		
		if (i >= k - 1) {
			dp[i - k + 1] = curr;
		}
	}

	return dp;
}