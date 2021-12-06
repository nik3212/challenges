/*

189. Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.

Follow up:

* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* Could you do it in-place with O(1) extra space?

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]

Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

class Solution {
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0) {
            return;
        }
        
        int g = gcd(nums.size(), k);
        int n = nums.size();

        k = k % n;

        for (int i = 0; i < g; ++i) {
            int temp = nums[abs(n - k + i) % n];
            int j = i;

            int local = nums[j % n];

            while (true) {
                int d = (j + k) % n;

                if (d == i) {
                    break;
                }

                int prev = nums[d];
                nums[d] = local;
                j = d;
                local = prev;
            }
            
            nums[(j + k) % n] = temp;
        }
    }
};