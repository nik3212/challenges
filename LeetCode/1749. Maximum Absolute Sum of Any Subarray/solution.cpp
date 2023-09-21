/*

1749. Maximum Absolute Sum of Any Subarray

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.

*/

class Solution {
private:
    int kadane_min(std::vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = min(res, sum);
            sum = min(sum, nums[i]);
        } 

        return res;
    }

    int kadane_max(std::vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, nums[i]);
        }

        return res;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max = abs(kadane_max(nums));
        int min = abs(kadane_min(nums));
        return std::max(max, min);
    }
};