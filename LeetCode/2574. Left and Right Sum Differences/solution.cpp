/*

2574. Left and Right Sum Differences

Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.
Where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return the array answer.

*/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] + nums[i - 1];
        }

        std::reverse(nums.begin(), nums.end());

        for (int i = 1; i < n; ++i) {
            right[i] = right[i - 1] + nums[i - 1];
        }

        std::reverse(right.begin(), right.end());

        std::vector<int> res(n, 0);

        for (int i = 0; i < n; ++i) {
            res[i] = abs(left[i] - right[i]);
        }

        return res;
    }
};