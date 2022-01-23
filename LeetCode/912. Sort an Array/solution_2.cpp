/*

912. Sort an Array

Given an array of integers nums, sort the array in ascending order.

*/

/*

Time Complexity: O(N*logN) where N is length of the input array
Space Complexity: O(N) where N is length of the input array

*/

class Solution {
private:
    void merge(std::vector<int>& nums, int l, int m, int r) {
        size_t left_size = m - l + 1;
        size_t right_size = r - m;

        std::vector<int> left;
        std::vector<int> right;

        for (int i = 0; i < left_size; ++i) {
            left.push_back(nums[l + i]);
        }

        for (int j = 0; j < right_size; ++j) {
            right.push_back(nums[m + j + 1]);
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                nums[k] = left[i++];
            } else {
                nums[k] = right[j++];
            }
            k++;
        }

        if (j == right.size()) {
            while (i < left.size()) {
                nums[k++] = left[i++];
            }
        }
    }

    void merge_sort(std::vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort(nums, l, m);
            merge_sort(nums, m + 1, r);
            merge(nums, l, m, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};