/*

918. Maximum Sum Circular Subarray

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum_max = 0;
        int res_max = nums[0];

        int sum_min = 0;
        int res_min = nums[0];

        int t = 0;

        for (int i = 0; i < n; ++i) {
            sum_max += nums[i];
            res_max = std::max(res_max, sum_max);
            sum_max = std::max(sum_max, 0);

            sum_min += nums[i];
            res_min = std::min(res_min, sum_min);
            sum_min = std::min(sum_min, 0);

            t += nums[i];
        }

        if (t == res_min) {
            return res_max;
        }

        return max(res_max, t - res_min);
    }
};