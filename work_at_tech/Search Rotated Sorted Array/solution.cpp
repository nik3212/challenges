/*

Search Rotated Sorted Array

You are given a list of unique integers which are sorted but rotated at some pivot. You are also given a target value and you have to find its index in the list. If it is not present in the list, return -1.

Example:
List: [4, 5, 6, 7, 1, 2, 3]
Target value: 6
Resultant index: 2

*/

int getElementIndex(vector<int> &array, int target) {
    int l = 0;
	int r = array.size() - 1;
	
	int n = array.size() - 1;
	
	while (l <= r) {
		int m = (l + r) / 2;
		
		if (array[m] > array[n]) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	int x = l;

	if (array[n] < target) {
		l = 0;
		r = x - 1;
	} else {
		l = x;
		r = n;
	}

	while (l <= r) {
		int m = (l + r) / 2;
		
		if (array[m] == target) {
			return m;
		} else if (array[m] < target) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	
	return -1;
}