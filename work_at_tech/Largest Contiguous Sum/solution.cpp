/*

Largest Contiguous Sum

A subarray is a part of an array including one or more contiguous/adjacent elements.

*/

int largestContiguousSum(vector <int> &arr){
    int res = arr[0];
	int sum = 0;
	
	for (int i = 0; i < arr.size(); ++i) {
		sum += arr[i];
		res = std::max(sum, res);
		sum = std::max(sum, 0);
	}
	
	return res;
}