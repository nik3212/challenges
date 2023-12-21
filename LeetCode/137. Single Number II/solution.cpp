/*

137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int o = 0;
        int t = 0;

        for (auto i : nums) {
            o ^= (i & ~t);
            t ^= (i & ~o);
        }

        return o;
    }
};