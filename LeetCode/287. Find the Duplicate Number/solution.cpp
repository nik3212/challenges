/*

287. Find the Duplicate Number

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;
            int ans = 0;

            for (int n: nums) {
                if (n <= m) { 
                    ans++;
                }
            }

            if (ans <= m) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return l;
    }
};