/*

57. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i++]);
        }

        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        res.push_back(newInterval);

        while (i < intervals.size()) {
            res.push_back(intervals[i++]);
        }

        return res;
    }
};