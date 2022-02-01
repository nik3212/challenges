/*

16. 3Sum Closest    

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

*/

/*

Time Complexity: O(N^2) where N is a length of the input array
Space Complexity: O(1)

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long sum = INT_MAX;

        std::sort(nums.begin(), nums.end());
        
        int k = 0;
        int m = 0;

        for (int i = 0; i < nums.size(); ++i) {
            
            k = i + 1;
            m = nums.size() - 1;
            
            while (k < m) {
                int local_sum = nums[i] + nums[k] + nums[m];

                if (local_sum == target) {
                    return local_sum;
                }

                if (abs(sum - target) > abs(local_sum - target)) {
                    sum = local_sum;
                }
                
                if (local_sum < target) {
                    k++;
                } else {
                    m--;
                }
                
            }
        }

        return sum;
    }
};