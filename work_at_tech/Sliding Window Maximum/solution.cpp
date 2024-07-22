/*

Sliding Window Maximum

You are given an array of integers A and a number k which represents the size of the window. The window covers k elements and starts at the left-end of the array. The window moves one index to the right at every step.

You need to return an array with the max element inside the window at every step.

*/

vector<int> maxSlidingWindow(vector<int> &A, int k) {
    std::deque<int> dq;
	std::vector<int> res;
	
	for (int i = 0; i < A.size(); ++i) {
		if (!dq.empty() && dq.front() == i - k) {
			dq.pop_front();
		}
		
		while (!dq.empty() && A[dq.back()] < A[i]) {
			dq.pop_back();
		}
		
		dq.push_back(i);
		
		if (i >= (k - 1)) {
			res.push_back(A[dq.front()]);
		}
	}
	
	return res;
}