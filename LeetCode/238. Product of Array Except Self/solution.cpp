/*

238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> v(n, 1);

        for (int i = 1; i < n; ++i) {
            v[i] = v[i - 1] * nums[i - 1];
        }

        int t = 1;
        for (int i = n - 1; i >= 0; i--) {
            v[i] *= t;
            t *= nums[i];
        }

        return v;
    }
};