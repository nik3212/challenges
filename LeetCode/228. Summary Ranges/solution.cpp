/*

228. Summary Ranges

You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> res;

        int n = nums.size();
        int prev = 0;

        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                continue;
            } else {
                int curr = i - 1;

                if (curr == prev) {
                    res.push_back(to_string(nums[prev]));
                } else {
                    res.push_back(to_string(nums[prev]) + "->" + to_string(nums[curr]));
                }

                prev = i;
            }
        }

        return res;
    }
};