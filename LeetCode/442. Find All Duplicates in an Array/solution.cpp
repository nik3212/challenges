/*

442. Find All Duplicates in an Array

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::set<int> s;
        std::vector<int> res;

        for (auto& i: nums) {
            if (s.find(i) != s.end()) {
                res.push_back(i);
            }
            s.insert(i);
        }

        return res;
    }
};