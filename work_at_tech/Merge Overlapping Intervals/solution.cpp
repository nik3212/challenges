/*

Merge Overlapping Intervals

Given a list of intervals, merge them to get a list of non-overlapping intervals.

intervali = [starti, endi]

Example:
Intervals: [[1, 2], [2, 3], [1, 4], [5, 6]]

[1, 2] and [2, 3] can be merged to form [1, 3].
Now, [1, 3] and [1, 4] can be merged to form [1, 4].
[1, 4] and [5, 6] have no intersection.
Hence above intervals are merged to form:
[[1, 4], [5, 6]]

Note that the final list should be in ascending order.

*/

vector<vector<int> > mergeIntervals(vector<vector<int> > &intervals) {
    std::vector<std::vector<int>> v;
	
	std::sort(intervals.begin(), intervals.end());
	
	for (int i = 0; i < intervals.size(); ++i) {
		if (v.empty() || intervals[i][0] > v.back()[1]) { v.push_back(intervals[i]); }
		else { v.back()[1] = std::max(v.back()[1], intervals[i][1]); }
	}
	
	return v;
}