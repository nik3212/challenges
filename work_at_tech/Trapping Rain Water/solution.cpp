/*

Trapping Rain Water

Given an array A where each element denotes a the height of blocks, calculate the total volume of water that can be trapped when it rains.

Note: one cubic block has a volume of 1 unit.

*/

int volumeOfTrappedRainWater(vector<int> &heights) {
    int l = 0;
	int r = heights.size() - 1;
	
	int lm = heights[l];
	int rm = heights[r];
	
	int w = 0;
	
	while (l < r) {
		if (lm < rm) {
			l++;
			lm = std::max(lm, heights[l]);
			w += lm - heights[l];
		} else {
			r--;
			rm = std::max(rm, heights[r]);
			w += rm - heights[r];
		}
	}
	
	return w;
}