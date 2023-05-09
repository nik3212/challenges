/*

2672. Number of Adjacent Elements With the Same Color

There is a 0-indexed array nums of length n. Initially, all elements are uncolored (has a value of 0).

You are given a 2D integer array queries where queries[i] = [indexi, colori].

For each query, you color the index indexi with the color colori in the array nums.

Return an array answer of the same length as queries where answer[i] is the number of adjacent elements with the same color after the ith query.

More formally, answer[i] is the number of indices j, such that 0 <= j < n - 1 and nums[j] == nums[j + 1] and nums[j] != 0 after the ith query.

*/

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        std::vector<int> ans;
        std::vector<int> nums(n, 0);

        int r = 0;

        for (int i = 0; i < queries.size(); ++i) {
            int k = queries[i][0];
            int c = queries[i][1];

            if (nums[k] && k - 1 >= 0 && nums[k] == nums[k - 1]) { r--; }
            if (nums[k] && k + 1 < n && nums[k] == nums[k + 1]) { r--; }

            nums[k] = c;

            if (k - 1 >= 0 && nums[k] == nums[k - 1]) { r++; }
            if (k + 1 < n && nums[k] == nums[k + 1]) { r++; }

            ans.push_back(r);
        }

        return ans;
    }
};