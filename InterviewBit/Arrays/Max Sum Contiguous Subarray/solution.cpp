/*

Max Sum Contiguous Subarray

Problem Description

Find the contiguous subarray within an array, A of length N which has the largest sum.

Problem Constraints

1 <= N <= 106
-1000 <= A[i] <= 1000

Input Format

The first and the only argument contains an integer array, A.

Output Format

Return an integer representing the maximum possible sum of the contiguous subarray.

*/

int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0;
    int ans = A[0];

    for (int i = 0; i < A.size(); ++i) {
        sum += A[i];
        ans = max(sum, ans);
        sum = max(sum, 0);
    }

    return ans;
}
