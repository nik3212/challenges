/*

2054. Two Best Non-Overlapping Events

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

*/

class Solution {
private:
    int next_index(int index, int key, std::vector<std::vector<int>> &events) {
        int high = events.size() - 1;
        int low = index;

        int res = events.size();

        while (low <= high) {
            int m = (low + high) / 2;

            if (events[m][0] > key) {
                high = m - 1;
                res = m;
            } else {
                low = m + 1;
            }
        }

        return res;
    }

    int max_two_events(std::vector<std::vector<int>> &events, std::vector<std::vector<int>> &dp, int index, int count) {
        if (index == events.size() || count == 2) { return 0; }

        if (dp[index][count] != -1) { return dp[index][count]; }

        int next = max_two_events(events, dp, index + 1, count);

        int new_index = next_index(index, events[index][1], events);
        int origin = events[index][2] + max_two_events(events, dp, new_index, count + 1);

        return dp[index][count] = max(next, origin);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        std::vector<std::vector<int>> dp(events.size(), std::vector<int>(2, -1));

        return max_two_events(events, dp, 0, 0);
    }
};