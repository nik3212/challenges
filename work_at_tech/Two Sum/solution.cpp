/*

Two Sum

Given an array A and an integer target, find the indices of the two numbers in the array whose sum is equal to the given target.

Note: The problem has exactly one solution. Do not use the same element twice.

*/

pair<int,int> twoSum(vector<int> &A, int target) {
    int n = A.size();

	std::map<int, int> m;
	
	for (int i = 0; i < n; ++i) {
		int diff = target - A[i];
		
		if (m.find(diff) != m.end()) {
			return std::make_pair(i, m[diff]);
		}
		
		m[A[i]] = i;
	}
	
	throw("");
}