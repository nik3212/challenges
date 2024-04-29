/*

Three Sum

Given an array A, find all unique triplets in the array whose sum is equal to zero.

Example:
A: [1, 1, 0, -1, -2]
Triplets: [
  [-2, 1, 1],
  [-1, 0, 1]
]

Note: Each triplet should be sorted. The resultant array should be sorted as well.

*/

vector<vector<int>> threeSum(vector<int> &A) {
    std::sort(A.begin(), A.end());
	
	std::vector<std::vector<int>> res;
	
	for (int i = 0; i < A.size() - 2; ++i) {
		if (i == 0 || (i > 0 && A[i] != A[i - 1])) {
			int lo = i + 1;
			int hi = A.size() - 1;
			
			int sum = -1 * A[i];
			
			while (lo < hi) {
				if (A[lo] + A[hi] == sum) {
					std::vector<int> tmp;

					tmp.push_back(A[i]);
					tmp.push_back(A[lo]);
					tmp.push_back(A[hi]);
					
					
					res.push_back(tmp);
					
					while (lo < hi && A[lo] == A[lo + 1]) {
						lo++;
					}
					
					while(lo < hi && A[hi] == A[hi - 1]) {
						hi--;
					}
					
					lo++;
					hi--;
				} else if (A[lo] + A[hi] < sum) {
					lo++;
				} else {
					hi--;
				}
			}
		}
	}
	
	return res;
}