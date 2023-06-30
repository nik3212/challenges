/*

673. Number of Longest Increasing Subsequence

Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        std::vector<int> len(nums.size(), 1);
        std::vector<int> count(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if (len[i] == len[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int m = 0;
        for (int i = 0; i < len.size(); ++i) {
            m = std::max(m, len[i]);
        }

        int res = 0;
        for (int i = 0; i < count.size(); ++i) {
            if (len[i] == m) { res += count[i]; }
        }

        return res;
    }
};