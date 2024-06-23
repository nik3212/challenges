/*

Largest Rectangle in Histogram

You are given a list of non-negative integers denoting the bar heights of a histogram. All the bars have a width of 1. You need to find the area of the largest possible rectange in the histogram.

*/

int getLargestArea(std::vector<int> &heights) {
	int n = heights.size();
	
    std::vector<int> l(n);
	std::vector<int> r(n);
	
	l[0] = -1;
	r[n - 1] = n;

	for (int i = 1; i < heights.size(); ++i) {
		int p = i - 1;
		
		while (p >= 0 && heights[p] >= heights[i]) {
			p = l[p];
		}
		
		l[i] = p;
	}
	
	for (int i = n - 2; i >= 0; --i) {
		int p = i + 1;
		
		while (p < n && heights[p] >= heights[i]) {
			p = r[p];
		}
		
		r[i] = p;
	}
	
	int res = 0;
	
	for (int i = 0; i < n; ++i) {
		res = std::max(res, heights[i] * (r[i] - l[i] - 1));
	}
	
	return res;
}
