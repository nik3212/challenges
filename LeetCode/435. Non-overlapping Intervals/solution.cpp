/*

435. Non-overlapping Intervals

Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of 
the intervals non-overlapping.

*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end());

        int res = 0;
        int curr = -1000000;

        for (int i = 0; i < n; ++i) {
            std::cout << intervals[i][0] << " " << intervals[i][1] << std::endl;

            if (intervals[i][0] >= curr) {
                curr = intervals[i][1];
            } else {
                res++;
                curr = std::min(curr, intervals[i][1]);
            }
        }

        return res;
    }
};