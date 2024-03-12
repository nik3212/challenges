/*

1984. Minimum Difference Between Highest and Lowest of K Scores

You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int res = INT_MAX;

        for (int i = 0; i <= nums.size() - k; ++i) {
            res = std::min(nums[i + k - 1] - nums[i], res);
        }

        return res;
    }
};