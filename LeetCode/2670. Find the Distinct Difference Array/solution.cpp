/*

2670. Find the Distinct Difference Array

You are given a 0-indexed array nums of length n.

The distinct difference array of nums is an array diff of length n such that diff[i] is equal to the number of distinct elements in the suffix nums[i + 1, ..., n - 1] subtracted from the number of distinct elements in the prefix nums[0, ..., i].

Return the distinct difference array of nums.

Note that nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j inclusive. Particularly, if i > j then nums[i, ..., j] denotes an empty subarray.

*/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();

        std::set<int> pr;
        std::unordered_map<int, int> sf;

        std::vector<int> diff(n, 0);

        int pr_n = 0;
        int sf_n = 0;
    
        for (int i = 1; i < n; ++i) {
            if (sf.count(nums[i]) == 0) {
                sf_n++;
            }
            sf[nums[i]]++;
        }
        
        for (int i = 0; i < n; ++i) {
            if (pr.count(nums[i]) == 0) {
                pr.insert(nums[i]);
                pr_n++;
            }
            
            diff[i] = pr_n - sf_n;

            if (i < n - 1) {
                sf[nums[i + 1]]--;
                
                if (sf[nums[i + 1]] == 0) {
                    sf_n--;
                }
            }
        }
        
        return diff;
    }
};