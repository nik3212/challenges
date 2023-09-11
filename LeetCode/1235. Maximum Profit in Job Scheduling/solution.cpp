/*

1235. Maximum Profit in Job Scheduling

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

*/

class Solution {
private:
    int next_index(int key, int low, std::vector<std::vector<int>> &events) {
        int high = events.size() - 1;

        int ans = events.size();

        while (low <= high) {
            int m = (low + high) / 2;

            if (events[m][0] >= key) {
                high = m - 1;
                ans = m;
            } else {
                low = m + 1;
            }
        }

        return ans;
    }

    int dfs(int index, std::vector<int> &dp, std::vector<std::vector<int>> &events) {
        if (index == dp.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int next = dfs(index + 1, dp, events);

        int new_index = next_index(events[index][1], index, events);
        int origin = events[index][2] + dfs(new_index, dp, events);

        return dp[index] = max(origin, next);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        std::vector<std::vector<int>> events;
        std::vector<int> dp(n, -1);

        for (int i = 0; i < n; ++i) {
            events.push_back({ startTime[i], endTime[i], profit[i] });
        }

        std::sort(events.begin(), events.end());

        return dfs(0, dp, events);
    }
};