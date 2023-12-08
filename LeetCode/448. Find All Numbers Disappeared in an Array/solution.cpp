/*

448. Find All Numbers Disappeared in an Array

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

*/

class Solution {
private:
    void sort(std::vector<int> &nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int idx = nums[i] - 1;

            if (i == idx || nums[idx] == nums[i]) {
                i++;
            } else {
                std::swap(nums[i], nums[idx]);
            }
        }
    }
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> ans;

        sort(nums);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) { ans.push_back(i + 1); }
        }

        return ans;
    }
};