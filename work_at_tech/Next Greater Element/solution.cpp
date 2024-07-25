/*

Next Greater Element

Given an array of positive integers A, find the first greater number for every element on its right. If a greater number does not exist, use -1.

Example:
Input: [1, 5, 2, 3, 5]
Output: [5, -1, 3, 5, -1]

*/

vector<int> getNextGreaterElement (vector<int> &A) {
	int n = A.size();
	std::vector<int> res(n, -1);
	
	std::stack<int> s;
	
	for (int i = n - 1; i >= 0; --i) {
		while (!s.empty() && A[i] >= s.top()) {
			s.pop();
		}
		
		if (s.empty()) {
			res[i] = -1;
		} else {
			res[i] = s.top();
		}
		
		s.push(A[i]);
	}
	
	return res;
}