/*

Inversion Count

The inversion count of an array denotes how far is the array from being sorted.

If the array is sorted, inversion count is 0. If the array is sorted in reverse order, the inversion count is maximum.

More formally, the inversion count of an array A is the number of pairs (i, j) such A[i] < A[j] and i > j.

Example
Lets take the following array:
8, 4, 1, 2

This array has an inversion count of 5.
(8, 4), (8, 1), (8, 2), (4, 1), (4, 2)

Given an array A, calculate the inversion count of the array.

*/

int merge(std::vector<int> &v, int l, int m, int r) {
	std::vector<int> left;
	std::vector<int> right;
	
	for (int i = 0; i < (m - l + 1); ++i) {
		left.push_back(v[l + i]);
	}
	
	for (int i = 0; i < (r - m); ++i) {
		right.push_back(v[m + i + 1]);
	}
	
	int i = 0;
	int j = 0;
	
	int k = l;
	
	int res = 0;
	
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			v[k] = left[i];
			i++;
		} else {
			v[k] = right[j];
			j++;
			
			res += (left.size() - i);
		}
		
		k++;
	}
	
	while (i < left.size()) {
		v[k++] = left[i++];
	}
	
	while (j < right.size()) {
		v[k++] = right[j++];
	}
	
	return res;
}

int merge_sort(std::vector<int> &v, int l, int r) {
	int res = 0;

	if (l < r) {
		int m = (l + r) / 2;
		
		res += merge_sort(v, l, m);
		res += merge_sort(v, m + 1, r);
		
		res += merge(v, l, m, r);
	}
	
	return res;
}

int getInversionCount(vector<int> &array) {
	return merge_sort(array, 0, array.size() - 1);
}
