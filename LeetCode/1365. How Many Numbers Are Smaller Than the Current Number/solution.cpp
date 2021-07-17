/*

1365. How Many Numbers Are Smaller Than the Current Number

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

*/

class Solution {
private:
    int binary_search(std::vector<int>& v, int key) {
        int l = 0;
        int r = v.size() - 1;

        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (v[mid] == key) {
                ans = mid;
                r = mid - 1;
            } else if (v[mid] < key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector<int> sorted(nums.size());
        
        std::copy(nums.begin(), nums.end(), sorted.begin());
        std::sort(sorted.begin(), sorted.end());

        std::vector<int> result(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            result[i] = binary_search(sorted, nums[i]);
        }

        return result;
    }
};