/*

912. Sort an Array

Given an array of integers nums, sort the array in ascending order.

*/

/*

Time Complexity: O(N) where N is length of the input array
Space Complexity: O(N) where N is length of the input array

*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::map<int, int> m;

        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]]++;
        }

        std::vector<int> result;

        for (auto it: m) {
            for (int i = 0; i < it.second; ++i) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};