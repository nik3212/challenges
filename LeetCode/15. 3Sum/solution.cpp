/*

15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int lo = i + 1;
                int hi = nums.size() - 1;

                int sum = 0 - nums[i];

                while (lo < hi) {
                    if (nums[lo] + nums[hi] == sum) {
                        std::vector<int> tmp;

                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[lo]);
                        tmp.push_back(nums[hi]);

                        res.push_back(tmp);

                        while (lo < hi && nums[lo] == nums[lo + 1]) {
                            lo++;
                        }

                        while (lo < hi && nums[hi] == nums[hi - 1]) {
                            hi--;
                        }

                        lo++;
                        hi--;
                    } else if (nums[lo] + nums[hi] < sum) {
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }

        return res;
    }
};