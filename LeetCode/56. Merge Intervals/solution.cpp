/*

56. Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> res;
        std::sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); ++i) {
            if (res.empty() || intervals[i][0] > res.back()[1]) { res.push_back(intervals[i]); }
            else { res.back()[1] = std::max(res.back()[1], intervals[i][1]); }
        }

        return res;
    }
};