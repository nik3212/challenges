/*

2389. Longest Subsequence With Limited Sum

You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

*/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        std::sort(nums.begin(), nums.end());
        std::vector<int> pr = std::vector(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            pr[i] += pr[i - 1] + nums[i - 1];
        }

        std::vector<int> r(m, 0);

        for (int i = 0; i < m; ++i) {
            int val = queries[i];
            int c = 0;

            for (int j = 1; j <= n; ++j) {
                if (pr[j] <= val) {
                    c++;
                }
            }

            r[i] = c;
        }

        return r;
    }
};