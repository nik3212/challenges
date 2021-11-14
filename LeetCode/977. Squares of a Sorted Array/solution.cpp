/*

977. Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> v(n);

        int i = 0;
        int k = n - 1;
        int p = n - 1;

        while(i <= k) {
            if (abs(nums[i]) > nums[k]) {
                v[p--] = nums[i] * nums[i];
                i++;
            } else {
                v[p--] = nums[k] * nums[k];
                k--;
            }
        }

        return v;
    }
};