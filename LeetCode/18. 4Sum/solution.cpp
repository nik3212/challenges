/*

18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

*/

class Solution {
private:
    std::vector<std::vector<int>> two_sum(std::vector<int> &nums, long long target, int start) {
        std::vector<std::vector<int>> res;
        std::unordered_set<long long> s;

        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({ (int)(target - nums[i]), nums[i] });
                }
            }

            s.insert(nums[i]);
        }

        return res;
    }

    std::vector<std::vector<int>> k_sum(std::vector<int> &nums, long long target, int start, int k) {
        std::vector<std::vector<int>> res;

        if (start == nums.size()) {
            return res;
        }

        if (k == 2) {
            return two_sum(nums, target, start);
        }

        long long average_value = target / k;

        if (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                std::vector<std::vector<int>> v = k_sum(nums, target - nums[i], i + 1, k - 1);

                for (auto &k: v) {
                    std::vector<int> tmp = { nums[i] };
                    tmp.insert(tmp.end(), k.begin(), k.end());
                    res.push_back(tmp);
                }
            }
        }

        return res;
    }
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return k_sum(nums, target, 0, 4);
    }
};
