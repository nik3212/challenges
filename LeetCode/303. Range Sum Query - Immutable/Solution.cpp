/*

303. Range Sum Query - Immutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:

Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:

1. You may assume that the array does not change.
2. There are many calls to sumRange function.

*/

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums.resize(nums.size() + 1, 0);
        
        for (size_t i = 0; i < nums.size(); ++i) {
            this->nums[i + 1] = this->nums[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return nums[j + 1] - nums[i];
    }
};