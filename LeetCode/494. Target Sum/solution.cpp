/*

494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

*/

class Solution {
private:
    int count = 0;

    void helper(
        std::vector<int> &nums,
        int sum,
        int target,
        int level
    ) {
        if (level == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }

        helper(nums, sum + nums[level], target, level + 1);
        helper(nums, sum - nums[level], target, level + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, 0, target, 0);
        return count;
    }
};